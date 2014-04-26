TEMPLATE = lib
TARGET=../libs/feeda
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
