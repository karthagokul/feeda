#ifndef FEEDAENGINE_H
#define FEEDAENGINE_H

#include <QObject>
#include <QPointer>

#include "feedadownloader.h"

namespace Core {

class FeedaDownloader;
class FeedaChannel;

class FeedaEngine : public QObject
{
    Q_OBJECT
private:
    /**
     * @brief FeedaEngine
     * @param parent
     * Constructor
     */
    explicit FeedaEngine(QObject *parent = 0);

    void processRssData(const QString &aRssString);

public:
    enum Error
    {
        RssXMLParseError
    };

    /**
     * @brief instance
     * @return Returns Instance
     */
    static FeedaEngine *instance();

    /**
     * @brief addRssFeed
     * @param aFeedUrl URL String to the feed
     */
    void addRssFeed(const QString &aFeedUrl);

signals:
    void error(const Error &aError);

public slots:

private slots:
    void onDownloadEngineStatusChanged(const FeedaDownloader::State &aState);

private:
    static FeedaEngine *mSelf;
    QPointer<FeedaDownloader> mDownloadEngine;
    QList<QPointer<FeedaChannel> > mChannels;

};

}

#endif // FEEDAENGINE_H
