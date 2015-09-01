#include <QtGui>

#include "candydialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setStyle(new QPlastiqueStyle);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    QFile file(":/qss/candy.qss");
    file.open(QFile::ReadOnly);
    app.setStyleSheet(file.readAll());
    CandyDialog dialog;
    dialog.show();

    return app.exec();
}
