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
#ifndef FEEDASTORY_H
#define FEEDASTORY_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QDateTime>
#include <QDomDocument>

namespace Core {

class FeedaStory : public QObject
{
    Q_OBJECT
public:
    explicit FeedaStory(const QDomElement &aChannelElement,QObject *parent = 0);

    bool isValid() const
    {
        return mValid;
    }

    QString id() const
    {
        return mGuid;
    }

    bool read() const
    {
        return mRead;
    }

    void setRead(bool aRead)
    {
        mRead=aRead;
    }

    void printinfo();

private:

    /**
     * @brief parseInputString
     * @param aChannelInputStr
     * The function which constructs members from an input string
     */
    void parse(const QDomElement &aChannelElement);

public slots:

private:

    bool mValid;

    bool mRead;

    // The below member variables are part of RSS 2.0 specification

    /**
     * @brief mTitle
     */
    QString mTitle;

    /**
     * @brief mLink
     */
    QUrl mLink;

    /**
     * @brief mDescription
     */
    QString mDescription;

    /**
     * @brief mAuthor
     */
    QString mAuthor;

    /**
     * @brief mCategory
     */
    QString mCategory;

    /**
     * @brief mComments
     */
    QUrl mComments;

    /**
     * @brief mEnclosure
     */
    QString mEnclosure;

    /**
     * @brief mGuid
     * Thie field is the Url to the particular item
     */
    QString mGuid;

    /**
     * @brief mPubDate
     */
    QDateTime mPubDate;

    /**
     * @brief mSource
     */
    QUrl mSource;

};

}

#endif // FEEDASTORY_H
