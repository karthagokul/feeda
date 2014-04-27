#include "feedastorybank.h"
#include <QDebug>

Singleton *Singleton::_instance = 0;
Destroyer < > Singleton::_destroyer;


FeedaStoryBank::FeedaStoryBank()
{
    qDebug()<<"Creating ";
}
FeedaStoryBank::~FeedaStoryBank()
{
    qDebug()<<"Destroy";
}
