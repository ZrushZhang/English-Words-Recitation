#include <QtGui>
#include <QFile>
#include <QTime>
#include <QTimer>

#include "candydialog.h"

CandyDialog::CandyDialog(QWidget *parent)
{
    setupUi(this);

    //初始化所有控件和变量
    resetAllContents();
    wordsButton->hide();
    QTimer *lcdTimer = new QTimer;
    wordsLcdTimer->setNumDigits(19);
    wordsLcdTimer->setSegmentStyle(QLCDNumber::Flat);
    wordsLcdTimer->display(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    connect(lcdTimer,SIGNAL(timeout()),this,SLOT(chTime()));
    lcdTimer->start(1000);

    //设置输入规则
    QRegExp wordsRegx("[a-zA-Z- ]+$");
    QValidator *validator = new QRegExpValidator(wordsRegx, wordLineEdit);
    wordLineEdit->setValidator(validator);

    //设置联接槽
    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextTest()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(startTest()));
    connect(resetButton, SIGNAL(clicked()), this, SLOT(resetAll()));
    connect(methodComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(initialComboBoxHide(QString)));

    setWindowTitle("BEC Words Test");
}

void CandyDialog::startTest() {

    //初始化控件
    QString methodTestName = methodComboBox->currentText();
    startButton->setText(tr("停止测试"));
    nextButton->setEnabled(true);
    nextButton->setDefault(true);
    wordsButton->setEnabled(true);
    wordLineEdit->clear();
    referenceListWidget->clear();
    wordLineEdit->setFocus();

    //隐藏不需要的控件
    initControlWidgetForHide();
    //初始化全局变量
    initAllVariable();
    //存储单词
    wordsStore();

    //判断是否有单词存在
    QString getLetter = initialComboBox->currentText();
    wordsNums = lettersRecord.value(getLetter);
    if(wordsNums == 0){
        QMessageBox::information(0,QString("BEC单词测试"),QString("没有可用的单词,请选择其它方式测试."),QMessageBox::Ok);
        return;
    }
    //修改单词长度,单词索引范围逐渐缩小
    wordsEnds = wordsNums - 1;
    //初始化进度条
    progressBar->setRange(0,wordsNums);

    if(methodTestName == "随机测试"){
        wordsEnds = totalWordsRecord - 1;
        if(words100->isChecked()){
            wordsRandomTotalNums = 100;
        } else if(words300->isChecked()){
            wordsRandomTotalNums = 300;
        } else if(words500->isChecked()) {
            wordsRandomTotalNums = 500;
        } else if(words700->isChecked()) {
            wordsRandomTotalNums = 700;
        } else if(words1000->isChecked()) {
            wordsRandomTotalNums = 1000;
        }
        wordsRandomCount = wordsRandomTotalNums;
        //初始化进度条
        progressBar->setRange(0,wordsRandomTotalNums);
    }

    if(methodTestName == "随机测试"){
        beforeLetterNums = 0;
    } else if(methodTestName == "单词测试" || methodTestName == "词组测试"){
        //获取前面所有单词的数量
        QByteArray tmp = getLetter.toLatin1();
        char *letter = tmp.data();
        beforeLetterNums = 0;
        for(int i = 'A'; i < *letter; i++) {
            const char tmp = (const char)i;
            QString getLetterQString = QString(tmp);
            beforeLetterNums += lettersRecord.value(getLetterQString);
        }
    }

    //联接信号
    disconnect(startButton,SIGNAL(clicked()),this,SLOT(startTest()));
    connect(startButton,SIGNAL(clicked()),this,SLOT(stopTest()));

    //记录单词测试开始时间
    wordsElapseTime.start();

    //第一个测试单词显示
    startFlag = 1;
    nextTest();
}


void CandyDialog::nextTest() {

    //初始化控件
    wordLineEdit->setFocus();
    QString methodTestName = methodComboBox->currentText();

    //检查单词测试是否结束
    if(methodTestName == "随机测试"){
        //进度条添加
        progressBar->setValue(wordsRandomTotalNums-wordsRandomCount);
        //判断是否结束
        if(wordsRandomCount < 0){
            showAnswer();
            finishTest();
            return;
        }
    } else if(methodTestName == "单词测试" || methodTestName == "词组测试"){
        //进度条添加
        progressBar->setValue(wordsNums-wordsEnds);
        //判断是否结束
        if (wordsEnds < 0){
            showAnswer();
            finishTest();
            return;
        }
    }

    //检查是否是第一个测试单词
    if(!startFlag){
        showAnswer();
    } else {
        startFlag = 0;
    }

    //根据首字母随机获取一个单词或词组,并显示在listWidget
    QTime time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    quint32 randomWord = qrand()%(wordsEnds+1);
    randomWord += beforeLetterNums;
    if(!BECWords[randomWord].englishWord.isEmpty() && !BECWords[randomWord].englishWordClass.isEmpty() && !BECWords[randomWord].englishWordForChinese.isEmpty()){
        referenceListWidget->addItem(new QListWidgetItem(BECWords[randomWord].englishWordClass+"   "+BECWords[randomWord].englishWordForChinese));
        referenceListWidget->scrollToBottom();
    }


    //替换获取的英文单词,保证随机的单词不重复
    swapBECWords(BECWords,randomWord);
    wordsEnds--;
    wordsRandomCount--;
}

void CandyDialog::showAnswer() {

    //检查单词是否正确
    QString yourWords = wordLineEdit->text();
    wordLineEdit->clear();
    if(BECWords[beforeLetterNums+wordsEnds+1].englishWord.contains("_"))
        BECWords[beforeLetterNums+wordsEnds+1].englishWord.replace("_"," ");
    QString showAnswer = BECWords[beforeLetterNums+wordsEnds+1].englishWord+"    "+BECWords[beforeLetterNums+wordsEnds+1].englishWordClass+"  "+BECWords[beforeLetterNums+wordsEnds+1].englishWordForChinese;

    //移除首项内容
    referenceListWidget->removeItemWidget(referenceListWidget->currentItem());
    if(yourWords == BECWords[beforeLetterNums+wordsEnds+1].englishWord){
        //统计单词正确数量
        wordsCorrect++;
        referenceListWidget->addItem(new QListWidgetItem(QIcon(QObject::tr(":/images/right.png")), showAnswer));
        referenceListWidget->scrollToBottom();
    } else {
        //统计单词错误数量
        wordsWrong++;
        referenceListWidget->addItem(new QListWidgetItem(QIcon(QObject::tr(":/images//wrong.png")), showAnswer));
        referenceListWidget->scrollToBottom();
    }
}

void CandyDialog::initialComboBoxHide(QString testMethod){
    initControlWidgetForHide();
    startButton->setDefault(true);
}

void CandyDialog::finishTest() {

    //统计结果
    getResult();
    //初始化控件
    initControlWidgetForFinishTest();
    //初始化全局变量
    initAllVariable();

    QMessageBox::information(0,QString("BEC单词测试"),QString("恭喜!!您已经完成了所有测试内容!"),QMessageBox::Ok);
}

void CandyDialog::wordsStore(){

    QFile BECWordsFile(":/BECWords.txt");
    if(!BECWordsFile.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(0,QString("BEC单词测试"),QString("没有找到BEC单词文件,请导入单词文件再进行测试."),  QMessageBox::Ok);
        return;
    } else {
        QTextStream stream(&BECWordsFile);
        QString line;
        QString getLetter;
        QString method = methodComboBox->currentText();
        totalWordsRecord = 0;
        quint32 tmpRecord = 0;
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
        do {
            line = stream.readLine();
            if(!line.isNull()){
                line = line.simplified();
                if(line.contains("BEC Letter For",Qt::CaseInsensitive))
                {
                    //存储上一次字母的所有单词数量
                    if(totalWordsRecord == 0){
                        getLetter = line.right(1);
                        lettersRecord.insert(getLetter,totalWordsRecord);
                    } else {
                        lettersRecord.insert(getLetter,totalWordsRecord-tmpRecord);
                    }

                    //记录下一个字母
                    getLetter = line.right(1);
                    tmpRecord = totalWordsRecord;
                } else {
                    QStringList BECWordsContent = line.split(" ");
                    if ( method == "单词测试" ){
                        if(!BECWordsContent.value(0).contains("_")){
                            BECWords[totalWordsRecord].englishWord = BECWordsContent.value(0);
                            BECWords[totalWordsRecord].englishWordClass = BECWordsContent.value(1);
                            BECWords[totalWordsRecord].englishWordForChinese = BECWordsContent.value(2);
                            totalWordsRecord++;
                        }
                    } else if ( method == "词组测试" ){
                        if(BECWordsContent.value(0).contains("_")){
                            BECWordsContent.value(0).replace("_"," ");
                            BECWords[totalWordsRecord].englishWord = BECWordsContent.value(0);
                            BECWords[totalWordsRecord].englishWordClass = BECWordsContent.value(1);
                            BECWords[totalWordsRecord].englishWordForChinese = BECWordsContent.value(2);
                            totalWordsRecord++;
                        }
                    } else if ( method == "随机测试" ){
                        if(BECWordsContent.value(0).contains("_")){
                            BECWordsContent.value(0).replace("_"," ");
                        }
                        BECWords[totalWordsRecord].englishWord = BECWordsContent.value(0);
                        BECWords[totalWordsRecord].englishWordClass = BECWordsContent.value(1);
                        BECWords[totalWordsRecord].englishWordForChinese = BECWordsContent.value(2);
                        totalWordsRecord++;
                    }
                }
            }
        } while (!line.isNull());

        //存储最后一个字母的所有单词数量
        lettersRecord.insert(getLetter,totalWordsRecord-tmpRecord);
    }
}

void CandyDialog::swapBECWords(struct BEC_Words_Store BECWords[],quint32 randomWord){

    struct BEC_Words_Store tmpWordContent;

    //将末尾单词和随机单词调换位置
    tmpWordContent.englishWord = BECWords[randomWord].englishWord;
    tmpWordContent.englishWordClass = BECWords[randomWord].englishWordClass;
    tmpWordContent.englishWordForChinese = BECWords[randomWord].englishWordForChinese;

    BECWords[randomWord].englishWord = BECWords[beforeLetterNums+wordsEnds].englishWord;
    BECWords[randomWord].englishWordClass = BECWords[beforeLetterNums+wordsEnds].englishWordClass;
    BECWords[randomWord].englishWordForChinese = BECWords[beforeLetterNums+wordsEnds].englishWordForChinese;

    BECWords[beforeLetterNums+wordsEnds].englishWord = tmpWordContent.englishWord;
    BECWords[beforeLetterNums+wordsEnds].englishWordClass = tmpWordContent.englishWordClass;
    BECWords[beforeLetterNums+wordsEnds].englishWordForChinese = tmpWordContent.englishWordForChinese;
}

void CandyDialog::resetAll(){

    QMessageBox::StandardButton standardButton = QMessageBox::information(0,QString("BEC单词测试"),QString("确定要重置所有测试信息吗?"),QMessageBox::Yes | QMessageBox::No);
    if(standardButton == QMessageBox::Yes){
        resetAllContents();
    } else {
        nextButton->setDefault(true);
    }
}

void CandyDialog::chTime(){

    //设置时间
    wordsLcdTimer->display(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

void CandyDialog::resetAllContents(){
    //初始化按键
    startButton->setText(tr("开始测试"));
    startButton->setDefault(true);
    nextButton->setEnabled(false);
    wordsButton->setEnabled(false);

    //初始化控件
    wordLineEdit->clear();
    methodComboBox->setEnabled(true);
    initialComboBox->setEnabled(true);
    methodComboBox->setCurrentIndex(0);
    initialComboBox->setCurrentIndex(0);
    referenceListWidget->clear();
    wordsTextBrowser->clear();
    progressBar->setValue(0);
    wordsRandomLabel->hide();
    words100->hide();
    words300->hide();
    words500->hide();
    words700->hide();
    words1000->hide();

    //联接信号
    disconnect(startButton,SIGNAL(clicked()),this,SLOT(stopTest()));
    connect(startButton,SIGNAL(clicked()),this,SLOT(startTest()));

    //初始化全局变量
    initAllVariable();
}

void CandyDialog::initAllVariable(){
    //初始化全局变量
    totalWordsRecord = 0;
    wordsNums = 0;
    wordsEnds = 0;
    wordsCorrect = 0;
    wordsWrong = 0;
    startTime = 0;
    endTime = 0;
    wordsRandomTotalNums = 0;
    beforeLetterNums = 0;
    startFlag = 0;
}

void CandyDialog::initControlWidgetForFinishTest(){

    //初始化按键
    startButton->setText(tr("开始测试"));
    startButton->setDefault(true);
    nextButton->setEnabled(false);
    wordsButton->setEnabled(false);

    //初始化控件
    wordLineEdit->clear();
    initControlWidgetForHide();

    //联接信号
    disconnect(startButton,SIGNAL(clicked()),this,SLOT(stopTest()));
    connect(startButton,SIGNAL(clicked()),this,SLOT(startTest()));
}

void CandyDialog::initControlWidgetForHide(){
    QString methodTestName = methodComboBox->currentText();
    if(methodTestName == "单词测试" || methodTestName == "词组测试"){
        initialLabel->show();
        initialComboBox->show();
        wordsRandomLabel->hide();
        words100->hide();
        words300->hide();
        words500->hide();
        words700->hide();
        words1000->hide();
    } else if(methodTestName == "随机测试"){
        initialLabel->hide();
        initialComboBox->hide();
        wordsRandomLabel->show();
        words100->show();
        words300->show();
        words500->show();
        words700->show();
        words1000->show();
    }
}

void CandyDialog::showEnglishList(){
    ;
}

void CandyDialog::stopTest(){

    QMessageBox::StandardButton standardButton = QMessageBox::information(0,QString("BEC单词测试"),QString("确定要停止当前测试吗?"),QMessageBox::Yes | QMessageBox::No);

    if(standardButton == QMessageBox::Yes){

        //统计结果
        getResult();
        //初始化控件
        initControlWidgetForFinishTest();
        //初始化全局变量
        initAllVariable();

    } else {
        nextButton->setDefault(true);
    }
}

void CandyDialog::getResult(){

    //统计数值
    double wordsPercent = (double)wordsCorrect/(wordsCorrect+wordsWrong);
    wordsPercent *= 100;
    QString wordsPercentQString = QString::number((int)wordsPercent);
    if(wordsCorrect == 0){
        wordsPercentQString = "0";
    }
    QString methodTestName = methodComboBox->currentText();
    QString testLetter;
    if(methodTestName == "单词测试" || methodTestName == "词组测试")
        testLetter = initialComboBox->currentText();

    //统计正确率
    wordsTextBrowser->append(tr("测试项目: %1").arg(methodTestName));
    if(!testLetter.isEmpty() && methodTestName != "随机测试")
        wordsTextBrowser->append(tr("测试首字母: %1").arg(testLetter.toUpper()));
    wordsTextBrowser->append(tr("单词数总计: %1").arg(wordsCorrect+wordsWrong));
    wordsTextBrowser->append(tr("答对单词数: %1").arg(wordsCorrect));
    wordsTextBrowser->append(tr("答错单词数: %1").arg(wordsWrong));
    wordsTextBrowser->append(tr("正确率: %%1").arg(wordsPercentQString));

    //统计测试时间
    endTime = wordsElapseTime.elapsed()/1000;
    QString timeElapse;
    if(endTime >= 3600 && endTime%3600 == 0){
        timeElapse = QString::number(endTime/3600,10) + "小时";
    } else if(endTime >= 3600 && endTime%3600 >=60) {
        timeElapse = QString::number(endTime/3600,10) + "小时" + QString::number(endTime%3600/60,10) + "分钟" + QString::number(endTime%3600%60,10) + "秒";
    } else if(endTime >= 3600 && endTime%3600 < 60){
        timeElapse = QString::number(endTime/3600,10) + "小时" + QString::number(endTime%3600%60,10) + "秒";
    } else if(endTime < 3600 && endTime >= 60){
        timeElapse = QString::number(endTime/60,10) + "分钟" + QString::number(endTime%60,10) + "秒";
    } else if(endTime < 60 && endTime >= 0) {
        timeElapse = QString::number(endTime%60,10) + "秒";
    }
    wordsTextBrowser->append(tr("测试用时: %1").arg(timeElapse));

    //结果分析
    wordsTextBrowser->append(tr("结果分析:"));
    if((int)wordsPercent < 30){
        wordsTextBrowser->append(tr("目测您的英语是语文老师教的..."));
    } else if ((int)wordsPercent < 60) {
        wordsTextBrowser->append(tr("还算不错,继续努力,胜利在向您招手~~"));
    } else if ((int)wordsPercent < 90) {
        wordsTextBrowser->append(tr("一般一般世界第三,如果您能再努力一些,我要请您吃冰激淋了!!!"));
    } else if ((int)wordsPercent < 100) {
        wordsTextBrowser->append(tr("功夫不负有心人,蛮厉害的嘛,不过不是完美100分,有点小遗憾!"));
    } else if ((int)wordsPercent == 100){
        wordsTextBrowser->append(tr("您已经不是地球人了...,快去拯救世界吧^_^"));
    } else {
        wordsTextBrowser->append(tr("没有结果显示..."));
    }
    wordsTextBrowser->append(tr(""));

    //初始化控件
    methodComboBox->setEnabled(true);
    initialComboBox->setEnabled(true);

    //初始化变量
    wordsCorrect = 0;
    wordsWrong = 0;
}
