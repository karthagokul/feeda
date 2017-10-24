TARGET = feeda
TEMPLATE = app

#Application Layer
SOURCES += main.cpp \
        mainwindow.cpp \
    feedappengine.cpp

HEADERS += \
    feedappengine.h
HEADERS  += mainwindow.h
FORMS    += mainwindow.ui
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#engine
QT+=network xml

HEADERS += \
    constants.h \
    feedadownloader.h \
    feedachannel.h \
    feedastory.h \
    feedaengine.h

SOURCES += \
    feedadownloader.cpp \
    feedachannel.cpp \
    feedastory.cpp \
    feedaengine.cpp



