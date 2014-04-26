#ifndef FEEDASTORY_H
#define FEEDASTORY_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QDateTime>

namespace Core {

class FeedaStory : public QObject
{
    Q_OBJECT
public:
    explicit FeedaStory(QString aChannelInputStr,QObject *parent = 0);

private:

    /**
     * @brief parseInputString
     * @param aChannelInputStr
     * The function which constructs members from an input string
     */
    void parseInputString(QString aChannelInputStr);

signals:

    /**
     * @brief error
     * Function to intimate if parsing error occured
     */
    void error();

public slots:

private:

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
