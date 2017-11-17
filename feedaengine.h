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
#ifndef FEEDAENGINE_H
#define FEEDAENGINE_H

#include <QObject>
#include <QPointer>
#include <QMap>

#include "feedadownloader.h"

namespace Core {

class FeedaDownloader;
class FeedaChannel;

class FeedaEngine : public QObject
{
    Q_OBJECT
private:

    void processRssData(const QString &aRssString);
    void processDownload(FeedaDownloader *aItem);

public:
    enum Error
    {
        RssXMLParseError
    };
    /**
     * @brief FeedaEngine
     * @param parent
     * Constructor
     */
    explicit FeedaEngine(QObject *parent=0);
    void start();
    void importOPMLFile(const QString &aPth);
    void stop();
    ~FeedaEngine();

    /**
     * @brief registerRssFeed
     * @param aFeedUrl URL String to the feed
     */
    bool registerRssFeed(const QString &aFeedUrl);
    QList<QPointer<FeedaChannel> > getChannels() const
    {
        return mChannels;
    }

signals:
    void error(const Error &aError);
    void ready();

public slots:

private slots:
    void onDownloadEngineStatusChanged(const FeedaDownloader::State &aState);

private:
    bool save();
    bool restore();

private:
    QList<QPointer<FeedaChannel> > mChannels;
    QList<QUrl> mFeeds;
    QList<QPointer<FeedaDownloader> > mActiveDowloads;
};

}

#endif // FEEDAENGINE_H
