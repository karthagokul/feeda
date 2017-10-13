#include "feedappengine.h"
#include "feedaengine.h"
#include <QQmlContext>

FeedAppEngine::FeedAppEngine(QObject *aParent):QQmlApplicationEngine(aParent)
{
    mEngine =new Core::FeedaEngine(this);
    mEngine->importOPMLFile("opml_sample.xml");
}

bool FeedAppEngine::start()
{
    //mEngine->start();
    QStringList dataList;
    dataList.append("Item 1");
    dataList.append("Item 2");
    dataList.append("Item 3");
    dataList.append("Item 4");
    QQmlContext *ctxt = rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    load(QUrl(QStringLiteral("qrc:///main.qml")));
    return true;
}
