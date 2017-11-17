TARGET = feeda
TEMPLATE = app

#Application Layer
SOURCES += main.cpp \
    feedappengine.cpp \
    rssmodel.cpp

HEADERS += \
    feedappengine.h \
    rssmodel.h
HEADERS  +=
FORMS    +=
QT       += core gui qml
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

OTHER_FILES += \
    main.qml

RESOURCES += \
    main.qrc



# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer.pri)
qtcAddDeployment()

DISTFILES += \
    StoryPane.qml \
    ChannelPane.qml \
    StoryPreview.qml
