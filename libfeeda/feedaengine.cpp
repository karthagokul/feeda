#include "feedaengine.h"
#include "feedachannel.h"

#include <QDomDocument>

using namespace Core;

FeedaEngine *FeedaEngine::mSelf=0;

FeedaEngine::FeedaEngine(QObject *parent) :
    QObject(parent)
{
}

FeedaEngine *FeedaEngine::instance()
{
    if(!mSelf)
    {
        mSelf=new FeedaEngine();
    }
    return mSelf;
}

void FeedaEngine::onDownloadEngineStatusChanged(const FeedaDownloader::State &aState)
{
    qDebug()<<__PRETTY_FUNCTION__;
    switch(aState)
    {
    case FeedaDownloader::Started:
        qDebug()<<"Download Started";
        break;
    case FeedaDownloader::Finished:
        qDebug()<<"Download Finished";
        processRssData(mDownloadEngine->data());
        break;
    }
}

void FeedaEngine::processRssData(const QString &aRssString)
{
    QDomDocument doc;
    QString errorMsg;
    int errorLine, errorColumn;
    if ( doc.setContent( aRssString, &errorMsg, &errorLine, &errorColumn ) )
    {
        QDomElement element = doc.documentElement();
        for(QDomNode n = element.firstChild(); !n.isNull(); n = n.nextSibling())
        {
            //here we have channel
            FeedaChannel *channel=new FeedaChannel(n.toElement(),this);
            if(channel->isValid())
            {
                channel->printinfo();
            }
            else
            {
                delete channel;
                channel=0;
            }
        }
    }

}

void FeedaEngine::addRssFeed(const QString &aFeedUrl)
{
    //checks if the download engine exists
    if(mDownloadEngine.isNull())
    {
        mDownloadEngine=new FeedaDownloader(this);
        //Connects to the Download Engine Events
        connect(mDownloadEngine,SIGNAL(stateChanged(const FeedaDownloader::State &)),this,SLOT(onDownloadEngineStatusChanged(const FeedaDownloader::State &)));
    }

    //initiates the download
    mDownloadEngine->start(aFeedUrl);
    return;
}
