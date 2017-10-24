#ifndef FEEDAPPENGINE_H
#define FEEDAPPENGINE_H

#include <QThread>

namespace Core
{
class FeedaEngine;
}


class FeedAppEngine : public QThread
{
public:
    FeedAppEngine(QObject *parent);
    void run();

private:
    Core::FeedaEngine* mEngine;
};

#endif // FEEDAPPENGINE_H
