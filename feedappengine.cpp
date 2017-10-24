#include "feedappengine.h"
#include "feedaengine.h"


FeedAppEngine::FeedAppEngine(QObject *parent):QThread(parent)
{
    mEngine =new Core::FeedaEngine();
    mEngine->importOPMLFile("opml_sample.xml");
}

void FeedAppEngine::run()
{

    //mEngine->start();
    return ;
}
