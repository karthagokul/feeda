#-------------------------------------------------
#
# Project created by QtCreator 2014-04-25T13:20:38
#
#-------------------------------------------------

QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../feeda
TEMPLATE = app

LIBS += -L../libs -lfeeda
INCLUDEPATH +=../libfeeda

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
