TEMPLATE = app


SOURCES += main.cpp \
    feedappengine.cpp

QT+=network xml widgets

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
    
RESOURCES +=

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    feedappengine.h
