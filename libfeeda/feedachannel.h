#ifndef FEEDACHANNEL_H
#define FEEDACHANNEL_H

#include <QObject>
#include <QList>
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

    QList<QPointer<FeedaStory> > mStories;

};

}

#endif // FEEDACHANNEL_H
