QT += core
QT -= gui

TARGET = test

CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += /home/jackey/Downloads/CTK-2023.07.13/Libs/Core \
               /home/jackey/Downloads/CTK-2023.07.13/Libs/PluginFramework \
               /home/jackey/Downloads/CTK-2023.07.13/build/CTK-build/Libs/PluginFramework \
               /home/jackey/Downloads/CTK-2023.07.13/build/CTK-build/Libs/Core
LIBS += -L/home/jackey/Downloads/CTK-2023.07.13/build/CTK-build/bin \
        -lCTKCore -lCTKPluginFramework

SOURCES += \
    main.cpp


