#ifndef FEEDAPPENGINE_H
#define FEEDAPPENGINE_H

#include <QQmlApplicationEngine>

class FeedAppEngine : public QQmlApplicationEngine
{
public:
    FeedAppEngine(QObject *aParent);
    bool start();
};

#endif // FEEDAPPENGINE_H
