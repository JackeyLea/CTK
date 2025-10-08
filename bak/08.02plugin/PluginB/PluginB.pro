QT         += core widgets
QT         -= gui

TARGET      = PluginB
TEMPLATE    = lib
CONFIG     += c++11
DESTDIR     = ../../bin/plugins
MOC_DIR     = moc
RCC_DIR     = rcc
UI_DIR      = ui
OBJECTS_DIR = obj

include($$PWD/../../CTK.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    mypluginservice.cpp \
    pluginactivator.cpp \
    widgetb.cpp

HEADERS += \
    mypluginservice.h \
    pluginactivator.h \
    widgetb.h

FORMS += \
    widgetb.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
