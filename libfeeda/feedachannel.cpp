#include "feedachannel.h"
#include <QDebug>


using namespace Core;

FeedaChannel::FeedaChannel(const QDomElement &aChannelElement,QObject *parent) :
    QObject(parent),mValid(true)
{
    qDebug()<<__PRETTY_FUNCTION__;
    parse(aChannelElement);
}

void FeedaChannel::parse(const QDomElement &aChannelElement)
{
    qDebug()<<__PRETTY_FUNCTION__;
    for(QDomNode n = aChannelElement.firstChild(); !n.isNull(); n = n.nextSibling())
    {
        QString text=n.toElement().text();
        QString tag=n.toElement().tagName();
        if(tag=="title")
        {
            mTitle=text;
        }
        else if(tag=="link")
        {
            mLink=QUrl(text);
        }
        else if(tag=="description")
        {
            mDescription=text;
        }
        else if(tag=="language")
        {
            mLanguage=text;
        }
        else if(tag=="pubDate")
        {
            mPubDate=QDateTime::fromString(text,Qt::SystemLocaleShortDate);
        }
        else if(tag=="lastBuildDate")
        {
            mLastBuildDate=QDateTime::fromString(text,Qt::SystemLocaleShortDate);
        }
        else if(tag=="docs")
        {
            mDocs=QUrl(text);
        }
        else if(tag=="generator")
        {
            mGenerator=text;
        }
        else if(tag=="managingEditor")
        {
            mManagingEditor=text;
        }
        else if(tag=="webMaster")
        {
            mWebMaster=text;
        }
        else if(tag=="item")
        {
            FeedaStory *story=new FeedaStory(n.toElement(),this);
            if(story->isValid())
            {
                mStories.insert(story->id(),story);
            }
            else
            {
                delete story;
                story=0;
            }
        }
    }
    printinfo();
}

void FeedaChannel::printinfo()
{
    qDebug();
    qDebug()<<"Channel";
    qDebug()<<"-------";
    qDebug()<<"Title : "<<mTitle;
    qDebug()<<"Url : "<<mLink.toString();
    qDebug()<<"Description : "<<mDescription;
}
