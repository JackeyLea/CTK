QT += core
QT -= gui

TARGET = testPlugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH += /home/jackey/Downloads/CTK-2023.07.13/Libs/Core \
               /home/jackey/Downloads/CTK-2023.07.13/Libs/PluginFramework \
               /home/jackey/Downloads/CTK-2023.07.13/build/CTK-build/Libs/PluginFramework \
               /home/jackey/Downloads/CTK-2023.07.13/build/CTK-build/Libs/Core

HEADERS += \
    testpluginactivator.h

SOURCES += \
    testpluginactivator.cpp

RESOURCES += \
    resource.qrc

