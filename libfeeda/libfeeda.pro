TEMPLATE = lib
TARGET=../libs/feeda
QT+=network xml

HEADERS += \
    constants.h \
    feedadownloader.h \
    feedaparser.h \
    feedachannel.h \
    feedastory.h \
    feedaengine.h

SOURCES += \
    feedadownloader.cpp \
    feedaparser.cpp \
    feedachannel.cpp \
    feedastory.cpp \
    feedaengine.cpp
