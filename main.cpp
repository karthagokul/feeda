#include "qtquick2applicationviewer.h"
#include "feedappengine.h"
#include "mainwindow.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QGuiApplication app(argc,argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    FeedAppEngine *aEngine=new FeedAppEngine(&app);
    aEngine->start();
    int ret= app.exec();
    delete aEngine;
    return ret;

}
