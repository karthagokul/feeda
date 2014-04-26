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
