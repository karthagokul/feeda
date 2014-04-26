#include "feedastory.h"

#include <QDebug>

using namespace Core;

FeedaStory::FeedaStory(QString aChannelInputStr,QObject *parent) :
    QObject(parent)
{
    parseInputString(aChannelInputStr);
}

void FeedaStory::parseInputString(QString aChannelInputStr)
{
    qDebug()<<__PRETTY_FUNCTION__;
    qDebug()<<aChannelInputStr;
}
