#include "spider.h"

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    QString filespec = QString("Spider_ru.qm"); // весь перевод сидит в этом файле
    translator.load(filespec,".");
    QApplication ::installTranslator(&translator);

    QString filespec2 = QString("qt_") + QLocale::system().name();
    QString directory = QLibraryInfo::location(QLibraryInfo::TranslationsPath);
    QTranslator translator2;
    translator2.load(filespec2, directory);
    QApplication ::installTranslator(&translator2);

    Spider w;
    w.show();

    return a.exec();
}
