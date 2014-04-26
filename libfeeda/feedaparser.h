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

#ifndef FEEDAPARSER_H
#define FEEDAPARSER_H

#include <QObject>
#include <QPointer>
#include "feedachannel.h"

namespace Core {

class FeedaParser : public QObject
{
    Q_OBJECT
public:
    explicit FeedaParser(QObject *parent = 0);
    void setData(QString aChannelInputStr);


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
    QList<QPointer<FeedaChannel> > mChannels;
};

}

#endif // FEEDAPARSER_H
