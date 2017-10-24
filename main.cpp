#include <QApplication>
#include "feedappengine.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    MainWindow w;
    w.show();

    FeedAppEngine f(&app);
    f.start();

    return app.exec();
}
