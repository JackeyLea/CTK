QT += core
QT -= gui

TARGET = testPlugin
TEMPLATE = lib
CONFIG += plugin

include(/home/jackey/Documents/github.com/CTK/CTK.pri)

HEADERS += \
    testpluginactivator.h

SOURCES += \
    testpluginactivator.cpp

RESOURCES += \
    resource.qrc

