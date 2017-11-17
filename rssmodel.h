#ifndef RSSMODEL_H
#define RSSMODEL_H

#include<QAbstractListModel>
#include "feedaengine.h"
#include "feedachannel.h"

namespace Core
{
class FeedaChannel;
class FeedaEngine;
}
using namespace Core;

class RssModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ChannelRole {
        TitleRole = Qt::UserRole + 1,
        DescriptionRole ,
        UrlRole
    };

    RssModel( Core::FeedaEngine* &aEngine,QObject *parent = 0)
    {
        mEngine=aEngine;

    }

    QHash<int, QByteArray> roleNames() const {
        QHash<int, QByteArray> roles;
        roles[TitleRole] = "Title";
        roles[DescriptionRole] = "Description";
        roles[UrlRole] = "Url";
        return roles;
    }
    int rowCount(const QModelIndex &parent) const
    {
        qDebug()<<"Row Count is Getting called"<< mEngine->getChannels().count()+1;
        return mEngine->getChannels().count();
    }

    QVariant data(const QModelIndex &index, int role) const
    {
        qDebug()<<"Ding"<<index.row() <<"And Channel Count is "<<mEngine->getChannels().count();
       // FeedaChannel *channel=mEngine->getChannels()[index.row()];
        return QVariant("Test Data  ");
    }
    FeedaEngine* mEngine;
};


#endif // RSSMODEL_H
