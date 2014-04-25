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

#ifndef DEFS_H
#define DEFS_H

#include<QString>
#include<QUrl>
#include<QDateTime>

namespace Core
{

/**
 * @brief The FeedaStory struct
 * It represents the RSS2.0 Item .
 */
struct FeedaStory{
    QString mTitle;
    QUrl mLink;
    QString mDescription;
    QString mAuthor;
    QString mCategory;
    QUrl mComments;
    QString mEnclosure;
    QString mGuid;
    QDateTime mPubDate;
    QUrl mSource;

};

/**
 * @brief The FeedaChannelImage struct
 * It Represents the channel image
 */
struct FeedaChannelImage{
    QUrl mUrl;
    QString mTitle;
    QUrl mLink;
    uint mHeight;
    uint mWidth;
};

/**
 * @brief The FeedaChannelCloud struct
 * TBD
 */
struct FeedaChannelCloud{

};

/**
 * @brief The FeedaChannel struct
 * The RSS2.0 Channel
 */
struct FeedaChannel{
    QString mTitle;
    QUrl mLink;
    QString mDescription;
    QString mLanguage;
    QString mCopyRight;
    QString mManagingEditor;
    QString mWebMaster;
    QDateTime mPubDate;
    QDateTime mLastBuildDate;
    QString mCategory;
    QString mGenerator;
    QUrl mDocs;
    QString mTtl;
    Image mImage;
    QString mTextInput;
    uint mSkipHours;
    uint mSkipDays;

};

}

#endif // DEFS_H
