/********************************************************************************
** Form generated from reading UI file 'candy.ui'
**
** Created: Tue Sep 1 14:36:39 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANDY_H
#define UI_CANDY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Candy
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *methodLabel;
    QComboBox *methodComboBox;
    QLabel *initialLabel;
    QComboBox *initialComboBox;
    QLabel *wordsRandomLabel;
    QHBoxLayout *horizontalLayout;
    QRadioButton *words100;
    QRadioButton *words300;
    QRadioButton *words500;
    QRadioButton *words700;
    QRadioButton *words1000;
    QLabel *wordLabel;
    QLineEdit *wordLineEdit;
    QLabel *referenceLabel;
    QListWidget *referenceListWidget;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *progressLabel;
    QProgressBar *progressBar;
    QLabel *wordsLcdTimerLabel;
    QLCDNumber *wordsLcdTimer;
    QLabel *wordsTextLabel;
    QTextBrowser *wordsTextBrowser;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *startButton;
    QPushButton *resetButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *nextButton;
    QPushButton *wordsButton;

    void setupUi(QWidget *Candy)
    {
        if (Candy->objectName().isEmpty())
            Candy->setObjectName(QString::fromUtf8("Candy"));
        Candy->resize(687, 623);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Candy->sizePolicy().hasHeightForWidth());
        Candy->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(Candy);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        methodLabel = new QLabel(Candy);
        methodLabel->setObjectName(QString::fromUtf8("methodLabel"));
        sizePolicy.setHeightForWidth(methodLabel->sizePolicy().hasHeightForWidth());
        methodLabel->setSizePolicy(sizePolicy);
        methodLabel->setAlignment(Qt::AlignCenter);
        methodLabel->setMargin(0);
        methodLabel->setIndent(-1);

        gridLayout->addWidget(methodLabel, 0, 0, 1, 1);

        methodComboBox = new QComboBox(Candy);
        methodComboBox->setObjectName(QString::fromUtf8("methodComboBox"));
        sizePolicy.setHeightForWidth(methodComboBox->sizePolicy().hasHeightForWidth());
        methodComboBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(methodComboBox, 0, 1, 1, 2);

        initialLabel = new QLabel(Candy);
        initialLabel->setObjectName(QString::fromUtf8("initialLabel"));
        sizePolicy.setHeightForWidth(initialLabel->sizePolicy().hasHeightForWidth());
        initialLabel->setSizePolicy(sizePolicy);
        initialLabel->setAlignment(Qt::AlignCenter);
        initialLabel->setMargin(0);

        gridLayout->addWidget(initialLabel, 1, 0, 1, 1);

        initialComboBox = new QComboBox(Candy);
        initialComboBox->setObjectName(QString::fromUtf8("initialComboBox"));
        sizePolicy.setHeightForWidth(initialComboBox->sizePolicy().hasHeightForWidth());
        initialComboBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(initialComboBox, 1, 1, 1, 2);

        wordsRandomLabel = new QLabel(Candy);
        wordsRandomLabel->setObjectName(QString::fromUtf8("wordsRandomLabel"));
        wordsRandomLabel->setEnabled(true);
        sizePolicy.setHeightForWidth(wordsRandomLabel->sizePolicy().hasHeightForWidth());
        wordsRandomLabel->setSizePolicy(sizePolicy);
        wordsRandomLabel->setAlignment(Qt::AlignCenter);
        wordsRandomLabel->setMargin(0);

        gridLayout->addWidget(wordsRandomLabel, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        words100 = new QRadioButton(Candy);
        words100->setObjectName(QString::fromUtf8("words100"));

        horizontalLayout->addWidget(words100);

        words300 = new QRadioButton(Candy);
        words300->setObjectName(QString::fromUtf8("words300"));

        horizontalLayout->addWidget(words300);

        words500 = new QRadioButton(Candy);
        words500->setObjectName(QString::fromUtf8("words500"));

        horizontalLayout->addWidget(words500);

        words700 = new QRadioButton(Candy);
        words700->setObjectName(QString::fromUtf8("words700"));

        horizontalLayout->addWidget(words700);

        words1000 = new QRadioButton(Candy);
        words1000->setObjectName(QString::fromUtf8("words1000"));

        horizontalLayout->addWidget(words1000);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 2);

        wordLabel = new QLabel(Candy);
        wordLabel->setObjectName(QString::fromUtf8("wordLabel"));
        sizePolicy.setHeightForWidth(wordLabel->sizePolicy().hasHeightForWidth());
        wordLabel->setSizePolicy(sizePolicy);
        wordLabel->setAlignment(Qt::AlignCenter);
        wordLabel->setMargin(0);

        gridLayout->addWidget(wordLabel, 3, 0, 1, 1);

        wordLineEdit = new QLineEdit(Candy);
        wordLineEdit->setObjectName(QString::fromUtf8("wordLineEdit"));
        sizePolicy.setHeightForWidth(wordLineEdit->sizePolicy().hasHeightForWidth());
        wordLineEdit->setSizePolicy(sizePolicy);
        wordLineEdit->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 30, 7);"));

        gridLayout->addWidget(wordLineEdit, 3, 1, 1, 2);

        referenceLabel = new QLabel(Candy);
        referenceLabel->setObjectName(QString::fromUtf8("referenceLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(referenceLabel->sizePolicy().hasHeightForWidth());
        referenceLabel->setSizePolicy(sizePolicy1);
        referenceLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        referenceLabel->setMargin(0);

        gridLayout->addWidget(referenceLabel, 4, 0, 1, 1);

        referenceListWidget = new QListWidget(Candy);
        referenceListWidget->setObjectName(QString::fromUtf8("referenceListWidget"));
        referenceListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        referenceListWidget->setTabKeyNavigation(false);
        referenceListWidget->setViewMode(QListView::ListMode);

        gridLayout->addWidget(referenceListWidget, 4, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        progressLabel = new QLabel(Candy);
        progressLabel->setObjectName(QString::fromUtf8("progressLabel"));
        progressLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(progressLabel);

        progressBar = new QProgressBar(Candy);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setValue(24);

        horizontalLayout_2->addWidget(progressBar);

        wordsLcdTimerLabel = new QLabel(Candy);
        wordsLcdTimerLabel->setObjectName(QString::fromUtf8("wordsLcdTimerLabel"));

        horizontalLayout_2->addWidget(wordsLcdTimerLabel);

        wordsLcdTimer = new QLCDNumber(Candy);
        wordsLcdTimer->setObjectName(QString::fromUtf8("wordsLcdTimer"));
        wordsLcdTimer->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 75 14pt \"Gill Sans\";\n"
"color: rgb(3, 255, 44);"));

        horizontalLayout_2->addWidget(wordsLcdTimer);


        gridLayout->addLayout(horizontalLayout_2, 5, 1, 1, 2);

        wordsTextLabel = new QLabel(Candy);
        wordsTextLabel->setObjectName(QString::fromUtf8("wordsTextLabel"));
        sizePolicy.setHeightForWidth(wordsTextLabel->sizePolicy().hasHeightForWidth());
        wordsTextLabel->setSizePolicy(sizePolicy);
        wordsTextLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        wordsTextLabel->setMargin(0);

        gridLayout->addWidget(wordsTextLabel, 6, 0, 1, 1);

        wordsTextBrowser = new QTextBrowser(Candy);
        wordsTextBrowser->setObjectName(QString::fromUtf8("wordsTextBrowser"));

        gridLayout->addWidget(wordsTextBrowser, 6, 1, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        startButton = new QPushButton(Candy);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout_4->addWidget(startButton);

        resetButton = new QPushButton(Candy);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setEnabled(true);

        horizontalLayout_4->addWidget(resetButton);


        gridLayout->addLayout(horizontalLayout_4, 7, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        nextButton = new QPushButton(Candy);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setEnabled(false);

        horizontalLayout_3->addWidget(nextButton);

        wordsButton = new QPushButton(Candy);
        wordsButton->setObjectName(QString::fromUtf8("wordsButton"));
        wordsButton->setEnabled(false);

        horizontalLayout_3->addWidget(wordsButton);


        gridLayout->addLayout(horizontalLayout_3, 7, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        wordLabel->setBuddy(wordLineEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(methodComboBox, initialComboBox);
        QWidget::setTabOrder(initialComboBox, wordLineEdit);
        QWidget::setTabOrder(wordLineEdit, referenceListWidget);
        QWidget::setTabOrder(referenceListWidget, wordsTextBrowser);
        QWidget::setTabOrder(wordsTextBrowser, resetButton);

        retranslateUi(Candy);

        QMetaObject::connectSlotsByName(Candy);
    } // setupUi

    void retranslateUi(QWidget *Candy)
    {
        Candy->setWindowTitle(QApplication::translate("Candy", "Form", 0, QApplication::UnicodeUTF8));
        methodLabel->setText(QApplication::translate("Candy", "\350\257\267\351\200\211\346\213\251\344\275\240\347\232\204\346\265\213\350\257\225\346\226\271\345\274\217:", 0, QApplication::UnicodeUTF8));
        methodComboBox->clear();
        methodComboBox->insertItems(0, QStringList()
         << QApplication::translate("Candy", "\345\215\225\350\257\215\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "\350\257\215\347\273\204\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "\351\232\217\346\234\272\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8)
        );
        initialLabel->setText(QApplication::translate("Candy", "\350\257\267\351\200\211\346\213\251\351\246\226\345\255\227\346\257\215:", 0, QApplication::UnicodeUTF8));
        initialComboBox->clear();
        initialComboBox->insertItems(0, QStringList()
         << QApplication::translate("Candy", "A", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "B", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "C", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "G", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "H", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "I", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "J", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "L", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "N", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "O", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "P", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "Q", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "R", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "S", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "T", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "U", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "W", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "X", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "Y", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Candy", "Z", 0, QApplication::UnicodeUTF8)
        );
        wordsRandomLabel->setText(QApplication::translate("Candy", "\345\215\225\350\257\215\346\225\260\351\207\217:", 0, QApplication::UnicodeUTF8));
        words100->setText(QApplication::translate("Candy", "100", 0, QApplication::UnicodeUTF8));
        words300->setText(QApplication::translate("Candy", "300", 0, QApplication::UnicodeUTF8));
        words500->setText(QApplication::translate("Candy", "500", 0, QApplication::UnicodeUTF8));
        words700->setText(QApplication::translate("Candy", "700", 0, QApplication::UnicodeUTF8));
        words1000->setText(QApplication::translate("Candy", "1000", 0, QApplication::UnicodeUTF8));
        wordLabel->setText(QApplication::translate("Candy", "\350\257\267\350\276\223\345\205\245\345\215\225\350\257\215:", 0, QApplication::UnicodeUTF8));
        referenceLabel->setText(QApplication::translate("Candy", "\345\215\225\350\257\215\346\265\213\350\257\225\350\256\260\345\275\225:", 0, QApplication::UnicodeUTF8));
        progressLabel->setText(QApplication::translate("Candy", "\346\265\213\350\257\225\350\277\233\345\272\246:", 0, QApplication::UnicodeUTF8));
        wordsLcdTimerLabel->setText(QApplication::translate("Candy", " \346\265\213\350\257\225\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        wordsTextLabel->setText(QApplication::translate("Candy", "\346\265\213\350\257\225\347\273\223\346\236\234\347\273\237\350\256\241:", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("Candy", "\345\274\200\345\247\213\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("Candy", "\351\207\215\347\275\256\346\265\213\350\257\225\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("Candy", "\344\270\213\344\270\200\344\270\252\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
        wordsButton->setText(QApplication::translate("Candy", "\345\215\225\350\257\215\350\203\214\350\257\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Candy: public Ui_Candy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANDY_H
