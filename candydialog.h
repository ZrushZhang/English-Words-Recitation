#ifndef CANDYDIALOG_H
#define CANDYDIALOG_H

#include <QDialog>
#include <QString>
#include <QMap>
#include <QTextBrowser>
#include <QTime>

#include "ui_candy.h"

#define WORDCOUNT 2100

typedef struct BEC_Words_Store{
    QString englishWord;
    QString englishWordForChinese;
    QString englishWordClass;
}BEC_Words_Store;

class CandyDialog : public QDialog, public Ui::Candy
{
    Q_OBJECT

public:
    CandyDialog(QWidget *parent = 0);

private slots:
    void startTest();
    void stopTest();
    void resetAll();
    void nextTest();
    void chTime();
    void initialComboBoxHide(QString testMethod);
private:
    void showAnswer();
    void finishTest();
    void showEnglishList();
    void getResult();
    void wordsStore();
    void resetAllContents();
    void initAllVariable();
    void initControlWidgetForFinishTest();
    void initControlWidgetForHide();
    void swapBECWords(struct BEC_Words_Store BECWords[],quint32 randomWord);

private:
    QStringList letters;
    QMap<QString,quint32> lettersRecord;
    QTime wordsElapseTime;
private:
    quint32 startFlag;
    quint32 totalWordsRecord;
    quint32 beforeLetterNums;
    quint32 wordsNums;
    quint32 wordsCorrect;
    quint32 wordsWrong;
    quint32 startTime;
    quint32 endTime;
    qint32 wordsRandomTotalNums;
    qint32 wordsRandomCount;
    qint32 wordsEnds;
    struct BEC_Words_Store BECWords[WORDCOUNT];
};

#endif
