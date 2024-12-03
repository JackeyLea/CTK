QT         += core
QT         -= gui

TARGET      = testPlugin
TEMPLATE    = lib
CONFIG     += plugin
DESTDIR     = ../../bin
MOC_DIR     = moc
RCC_DIR     = rcc
UI_DIR      = ui
OBJECTS_DIR = obj

include($$PWD/../../CTK.pri)

HEADERS += \
    testpluginactivator.h

SOURCES += \
    testpluginactivator.cpp

RESOURCES += \
    resource.qrc

