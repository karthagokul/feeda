#include "feedappengine.h"
#include "feedaengine.h"
#include "feedachannel.h"
#include "rssmodel.h"


FeedAppEngine::FeedAppEngine(QObject *parent):QThread(parent),mRssModel(0)
{
    mEngine =new Core::FeedaEngine();
    mRssModel=new RssModel(mEngine);
    //mEngine->importOPMLFile("opml_sample.xml");
    connect(mEngine,SIGNAL(ready()),this,SLOT(populateModel()));
}

void FeedAppEngine::populateModel()
{
    int numberOfChannels=mEngine->getChannels().count();
   // mRssModel->populateData(mEngine->getChannels());
 //   qDebug()<<"Number of Channels"<<numberOfChannels;
//    for (int row = 0; row < numberOfChannels; ++row) {
//            QStandardItem *item = new QStandardItem();
//            item->setData(QVariant("Hello"),FeedAppEngine::DescRole);
//            item->setData(QVariant("Welcome"),FeedAppEngine::DescRole);
//            mRssModel->appendRow(item);
//    }
}
void FeedAppEngine::run()
{
    //mEngine->start();
    return ;
}

