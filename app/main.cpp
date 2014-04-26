#include "mainwindow.h"
#include <QApplication>

#include "feedadownloader.h"
#include "feedaparser.h"
#include "constants.h"
using namespace Core;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FeedaDownloader f(QString(RSS2SAMPLE_XML));
    f.start();
    FeedaParser parser;
    parser.setData(f.data());

    /*MainWindow w;
    w.show();*/

    return a.exec();
}
