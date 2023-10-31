QT       += core widgets
QT       -= gui

TARGET    = PluginA
TEMPLATE  = lib
CONFIG   += c++11

include(/home/jackey/Documents/github.com/CTK/CTK.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    pluginactivator.cpp \
    widgeta.cpp

HEADERS += \
    pluginactivator.h \
    widgeta.h

FORMS += \
    widgeta.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
