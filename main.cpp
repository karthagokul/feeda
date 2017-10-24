#include <QGuiApplication>

#include "feedappengine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc,argv);
    FeedAppEngine f(&app);
    f.start();

    return app.exec();
}
