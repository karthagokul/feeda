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

#include "feedaparser.h"

#include <QDebug>
#include <QXmlStreamReader>

using namespace Core;

FeedaParser::FeedaParser(QObject *parent) :
    QObject(parent)
{

}

void FeedaParser::setData(QString aChannelInputStr)
{
    parseInputString(aChannelInputStr);
}

void FeedaParser::parseInputString(QString aChannelInputStr)
{
    qDebug()<<__PRETTY_FUNCTION__;
    QXmlStreamReader xml(aChannelInputStr);
    while(!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        /* If token is just StartDocument, we'll go to next.*/
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }
        /* If token is StartElement, we'll see if we can read it.*/
        if(token == QXmlStreamReader::StartElement) {
            /* If it's named channel, we'll dig the information from there.*/
            if(xml.name() == "channel") {
                FeedaChannel *channel=new FeedaChannel(xml.text().toString(),this);
                if(channel->isValid())
                {
                    mChannels.append(channel);
                }
            }
        }
    }
    if(xml.hasError()) {
        emit error();
      }
}
