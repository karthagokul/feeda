#ifndef FEEDAENGINE_H
#define FEEDAENGINE_H

#include <QObject>

class FeedaEngine : public QObject
{
    Q_OBJECT
public:
    explicit FeedaEngine(QObject *parent = 0);

    bool addRssFeed(QString aFeedUrl);

signals:

public slots:

};

#endif // FEEDAENGINE_H
