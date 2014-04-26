#include "mainwindow.h"
#include <QApplication>

#include "feedaengine.h"
#include "constants.h"

using namespace Core;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FeedaEngine *mEngine=new FeedaEngine(&a);
    mEngine->registerRssFeed(QString(RSS2SAMPLE_XML));

    /*MainWindow w;
    w.show();*/

    return a.exec();
}
