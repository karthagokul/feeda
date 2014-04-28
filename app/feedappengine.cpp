#include "feedappengine.h"
#include <QQmlContext>

FeedAppEngine::FeedAppEngine(QObject *aParent):QQmlApplicationEngine(aParent)
{
}

bool FeedAppEngine::start()
{
    QStringList dataList;
    dataList.append("Item 1");
    dataList.append("Item 2");
    dataList.append("Item 3");
    dataList.append("Item 4");
    QQmlContext *ctxt = rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    load(QUrl(QStringLiteral("qrc:///main.qml")));
}
