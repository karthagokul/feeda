#ifndef FEEDAPPENGINE_H
#define FEEDAPPENGINE_H

#include <QQmlApplicationEngine>

namespace Core
{
class FeedaEngine;
}


class FeedAppEngine : public QQmlApplicationEngine
{
public:
    FeedAppEngine(QObject *aParent);
    bool start();

private:
    Core::FeedaEngine* mEngine;
};

#endif // FEEDAPPENGINE_H
