QT         += core
QT         -= gui

TARGET      = test
CONFIG     += console
CONFIG     -= app_bundle
DESTDIR     = ../../bin
MOC_DIR     = moc
RCC_DIR     = rcc
UI_DIR      = ui
OBJECTS_DIR = obj

include($$PWD/../../CTK.pri)

SOURCES += \
    main.cpp
