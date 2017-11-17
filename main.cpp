#include "qtquick2applicationviewer.h"
#include "feedappengine.h"
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <iostream>
#include <unistd.h>

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

    engine.rootContext()->setContextProperty("rssmodel",(QObject*)aEngine->mRssModel);

    int ret= app.exec();
    delete aEngine;
    return ret;

}
