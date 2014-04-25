#include "mainwindow.h"
#include <QApplication>

#include "feedadownloader.h"
#include "constants.h"
using namespace Core;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FeedaDownloader f(QString(RSS2SAMPLE_XML));
    f.start();

    /*MainWindow w;
    w.show();*/

    return a.exec();
}
