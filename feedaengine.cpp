#include "feedaengine.h"
#include "feedachannel.h"
#include "constants.h"

#include <QDomDocument>
#include <QDebug>
#include <QFile>
#include <QCoreApplication>

using namespace Core;

FeedaEngine::FeedaEngine(QObject *parent) :
    QObject(parent)
{
}

FeedaEngine::~FeedaEngine()
{

}

void FeedaEngine::importOPMLFile(const QString &aPth)
{
    QDomDocument doc;
    QString errorMsg;
    int errorLine, errorColumn;

    QFile file(aPth);
    if(!file.open(QFile::ReadOnly))
    {
        qDebug()<<"Unable to Open the OPML file";
        return;
    }
    QString content=QString(file.readAll());
    if ( doc.setContent( content, &errorMsg, &errorLine, &errorColumn ) )
    {
        QDomNodeList nodes = doc.elementsByTagName("outline");
        for(int i = 0; i < nodes.count(); i++)
        {
            QDomNode elm = nodes.at(i);
            if(elm.isElement())
            {
//                qDebug()<<i<<"->"<<elm.toElement().attribute("xmlUrl")<<","<<elm.toElement().attribute("type");
                //filtering out parent items
                if(elm.toElement().hasAttribute("xmlUrl"))
                    registerRssFeed(elm.toElement().attribute("xmlUrl"));
            }
        }
    }
}

void FeedaEngine::start()
{
    if(!restore())
    {
        qDebug()<<"Failed to restore configuration";
    }
}

void FeedaEngine::stop()
{
    if(!save())
    {
        qDebug()<<"Failed to save configuration";
    }

}


void FeedaEngine::onDownloadEngineStatusChanged(const FeedaDownloader::State &aState)
{
    //qDebug()<<__PRETTY_FUNCTION__;
    FeedaDownloader* item=(FeedaDownloader*)sender();
    switch(aState)
    {
    case FeedaDownloader::Started:
        qDebug()<<"Download Started";
        break;
    case FeedaDownloader::Finished:
        qDebug()<<"Download Finished";
        processDownload(item);
        break;
    case FeedaDownloader::Failed:
        qDebug()<<"Download Failed";
        processDownload(item);
        break;
    }
}

void FeedaEngine::processDownload(FeedaDownloader *aItem)
{
    //qDebug()<<__PRETTY_FUNCTION__;
    for(int i=0;i<mActiveDowloads.count();i++)
    {
        if(aItem==mActiveDowloads.at(i))
        {
            processRssData(aItem->data());
        }
        mActiveDowloads.removeAt(i);
    }
}

void FeedaEngine::processRssData(const QString &aRssString)
{
    qDebug()<<__PRETTY_FUNCTION__;
   // qDebug()<<aRssString;
    QDomDocument doc;
    QString errorMsg;
    int errorLine, errorColumn;
    if ( doc.setContent( aRssString, &errorMsg, &errorLine, &errorColumn ) )
    {
        QDomElement element = doc.documentElement();
        for(QDomNode n = element.firstChild(); !n.isNull(); n = n.nextSibling())
        {
            //We have got a channel,create an object now;
            FeedaChannel *channel=new FeedaChannel(n.toElement(),this);
            //Checks whether the channel is valid
            if(channel->isValid())
            {
                channel->printinfo();
                //appends to the channel info
                mChannels.append(channel);
            }
            else
            {
                delete channel;
                channel=0;
            }
        }
    }
    emit ready();
}

bool FeedaEngine::save()
{
    qDebug()<<__PRETTY_FUNCTION__;
    QFile file(CHANNELS_DATA);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    for(int i=0;i<mFeeds.count();i++)
    {
        out<<mFeeds.at(i).toString();
    }

    file.close();
    return true;
}

bool FeedaEngine::restore()
{
    qDebug()<<__PRETTY_FUNCTION__;
    QFile file(CHANNELS_DATA);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        registerRssFeed(line);
    }
    file.close();
    return true;
}

bool FeedaEngine::registerRssFeed(const QString &aFeedUrl)
{
    qDebug()<<__PRETTY_FUNCTION__;
    //Checks the feed is already registerd
    for(int i=0;i<mFeeds.count();i++)
    {
        if(mFeeds.at(i).toString()==aFeedUrl)
        {
            return false;
        }
    }

    FeedaDownloader *downloader=new FeedaDownloader(aFeedUrl,this);
    //Connects to the Downloader Events
    connect(downloader,SIGNAL(stateChanged(const FeedaDownloader::State &)),this,SLOT(onDownloadEngineStatusChanged(const FeedaDownloader::State &)));

    //adding it to active downloads
    mActiveDowloads.append(downloader);

    //Add it to the feed list
    mFeeds.append(QUrl(aFeedUrl));

    //initiates the download
    downloader->start();
    return true;
}
