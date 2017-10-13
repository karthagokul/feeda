TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    feedappengine.cpp

RESOURCES += qml.qrc

INCLUDEPATH=$$PWD/../libfeeda

LIBS +=-L ../libs/ -lfeeda

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    feedappengine.h
