#include "feedachannel.h"

#include <QDebug>
#include <QXmlStreamReader>

using namespace Core;

FeedaChannel::FeedaChannel(QString aChannelInputStr,QObject *parent) :
    QObject(parent),mValid(true)
{
    parseInputString(aChannelInputStr);
}

void FeedaChannel::parseInputString(QString aChannelInputStr)
{
    qDebug()<<__PRETTY_FUNCTION__;
    qDebug()<<aChannelInputStr;
}
