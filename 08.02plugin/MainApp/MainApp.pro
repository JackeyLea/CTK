QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = test
TEMPLATE    = app
CONFIG     += c++11
CONFIG     += console
CONFIG     -= app_bundle
DESTDIR     = ../../bin
MOC_DIR     = moc
RCC_DIR     = rcc
UI_DIR      = ui
OBJECTS_DIR = obj

include(/home/jackey/Documents/github.com/CTK/CTK.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
