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

#ifndef FEEDADOWNLOADER_H
#define FEEDADOWNLOADER_H

#include <QObject>
#include <QUrl>
#include <QNetworkAccessManager>

namespace Core
{

/**
 * @brief The FeedaDownloader class
 * The Class which is intended to download data from internet
 */
class FeedaDownloader : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief The State enum
     */
    enum State{
        Started,
        Finished
    };

    /**
     * @brief FeedaDownloader
     * @param parent Parent Object
     * Constructor
     */
    explicit FeedaDownloader(QObject *parent = 0);

    /**
     * @brief start
     * Function to start the operation
     */
    void start(const QString &aUrl);

    /**
     * @brief data
     * @return the downloaded data
     */
    QString data() const
    {
        return mData;
    }

    virtual ~FeedaDownloader();

protected slots:

    void onFinished(QNetworkReply *aReply);

signals:

    /**
     * @brief stateChanged
     * @param aState
     * This signal will inform the user about the various states
     */
    void stateChanged(const FeedaDownloader::State &aState);

private:
    QNetworkAccessManager *mManager;
    QString mData;

};

}

#endif // FEEDADOWNLOADER_H
