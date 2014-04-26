#ifndef FEEDAENGINE_H
#define FEEDAENGINE_H

#include <QObject>
#include <QPointer>
#include <QMap>

#include "feedadownloader.h"

namespace Core {

class FeedaDownloader;
class FeedaChannel;

class FeedaEngine : public QObject
{
    Q_OBJECT
private:

    void processRssData(const QString &aRssString);

    void processDownload(FeedaDownloader *aItem);


public:
    enum Error
    {
        RssXMLParseError
    };
    /**
     * @brief FeedaEngine
     * @param parent
     * Constructor
     */
    explicit FeedaEngine(QObject *parent);

    ~FeedaEngine();

    /**
     * @brief registerRssFeed
     * @param aFeedUrl URL String to the feed
     */
    bool registerRssFeed(const QString &aFeedUrl);

signals:
    void error(const Error &aError);

public slots:

private slots:
    void onDownloadEngineStatusChanged(const FeedaDownloader::State &aState);

private:
    void save();
    void restore();

private:
    QMap<QString,QPointer<FeedaChannel> > mChannels;

    QList<QUrl> mFeeds;

    QList<QPointer<FeedaDownloader> > mActiveDowloads;


};

}

#endif // FEEDAENGINE_H
