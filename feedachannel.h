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

#ifndef FEEDACHANNEL_H
#define FEEDACHANNEL_H

#include <QObject>
#include <QMap>
#include <QPointer>
#include <QString>
#include <QUrl>
#include <QImage>
#include <QDateTime>
#include <QDomDocument>
#include "feedastory.h"

namespace Core {

class FeedaStory;

class FeedaChannel : public QObject
{
    Q_OBJECT
public:
    explicit FeedaChannel(const QDomElement &aChannelElement,QObject *parent = 0);

    bool isValid() const
    {
        return mValid;
    }

    QString id() const
    {
        return mLink.toString();
    }

    void printinfo();

private:

    /**
     * @brief parseInputString
     * @param aChannelInputStr
     * The function which constructs members from an input string
     */
    void parse(const QDomElement &aChannelElement);

signals:


public slots:

private:
    void save();
    void restore();

private:

    bool mValid;

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
     * @brief mLanguage
     */
    QString mLanguage;

    /**
     * @brief mCopyRight
     */
    QString mCopyRight;

    /**
     * @brief mManagingEditor
     */
    QString mManagingEditor;

    /**
     * @brief mWebMaster
     */
    QString mWebMaster;

    /**
     * @brief mPubDate
     */
    QDateTime mPubDate;

    /**
     * @brief mLastBuildDate
     */
    QDateTime mLastBuildDate;

    /**
     * @brief mCategory
     */
    QString mCategory;

    /**
     * @brief mGenerator
     */
    QString mGenerator;

    /**
     * @brief mDocs
     */
    QUrl mDocs;

    /**
     * @brief mTtl
     */
    uint mTtl;

    /**
     * @brief mImage
     */
    QImage mImage;

    /**
     * @brief mTextInput
     */
    QString mTextInput;

    /**
     * @brief mSkipHours
     */
    uint mSkipHours;

    /**
     * @brief mSkipDays
     */
    uint mSkipDays;

    QMap<QString,QPointer<FeedaStory> > mStories;

};

}

#endif // FEEDACHANNEL_H
