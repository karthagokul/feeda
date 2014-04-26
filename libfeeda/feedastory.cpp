#include "feedastory.h"

#include <QDebug>

using namespace Core;

FeedaStory::FeedaStory(const QDomElement &aChannelElement,QObject *parent) :
    QObject(parent),mValid(true)
{
    parse(aChannelElement);
}

void FeedaStory::parse(const QDomElement &aChannelElement)
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
        else if(tag=="pubDate")
        {
            mPubDate=QDateTime::fromString(text,Qt::SystemLocaleShortDate);
        }
        else if(tag=="guid")
        {
            mGuid=text;
        }
    }
}

void FeedaStory::printinfo()
{
    qDebug();
    qDebug()<<"Story";
    qDebug()<<"-------";
    qDebug()<<"Title : "<<mTitle;
    qDebug()<<"Url : "<<mLink.toString();
    qDebug()<<"Description : "<<mDescription;
}
