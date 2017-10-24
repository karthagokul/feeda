/*
 * Public feeda header file
 * Copyright (C) 20013-2014 Gokul Kartha <kartha.gokul@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "feedadownloader.h"

#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkReply>

using namespace Core;

FeedaDownloader::FeedaDownloader(const QString &aUrl,QObject *parent) :
    QObject(parent),mManager(0),mUrl(aUrl)
{
    setObjectName(aUrl);
    mManager=new QNetworkAccessManager(this);
    connect(mManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onFinished(QNetworkReply*)));
}

void FeedaDownloader::onFinished(QNetworkReply *aReply)
{
    qDebug()<<__PRETTY_FUNCTION__;
    if(aReply->error()==QNetworkReply::NoError)
    {
        mData=QString(aReply->readAll());
        mState=FeedaDownloader::Finished;
    }
    else
    {
        mState=FeedaDownloader::Failed;
    }
    emit stateChanged(mState);
}

void FeedaDownloader::start()
{
    //qDebug()<<__PRETTY_FUNCTION__;
    mManager->get(QNetworkRequest(QUrl(mUrl)));
    emit stateChanged(FeedaDownloader::Started);
    return;
}

FeedaDownloader::~FeedaDownloader()
{
    if(mManager)
    {
        delete mManager;
        mManager=0;
    }
}
