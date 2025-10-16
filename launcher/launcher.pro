####################
#
# \author JackeyLea
# \date 2025.10.15
# \note 启动器
#
####################

QT  = core
QT -= gui

CONFIG     += c++17 cmdline console
CONFIG     -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# 库位置
CONFIG(debug,debug|release){
        DESTDIR = ../../debug
        TARGET=launcherd
        LIBS+= -L$$PWD/../3rd_party/debug/lib/ \
        -lCTKCore \
        -lCTKPluginFramework \
        -lqtadvanceddockingd

        # 编译后执行复制命令
        QMAKE_POST_LINK += xcopy /D /F /E /Y \"$${PWD}\\..\\3rd_party\\debug\\bin\" \"..\\..\\debug\"
}else{
        DESTDIR = ../../release
        TARGET=launcher
        LIBS+= -L$$PWD/../3rd_party/release/lib/ \
        -lCTKCore \
        -lCTKPluginFramework \
        -lqtadvanceddocking
}

# UTF-8编码
msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

# 头文件包含
INCLUDEPATH += $$PWD/../3rd_party/include/ctk/Libs/Core \
               $$PWD/../3rd_party/include/ctk/Libs/PluginFramework \
               $$PWD/../3rd_party/include/ctk/Libs/PluginFramework\service \
               $$PWD/../3rd_party/include/ctk/Libs/PluginFramework\service\event \
               $$PWD/../3rd_party/include/ctk/Libs/Widgets \
               $$PWD/../3rd_party/include/ctk \
               $$PWD/../3rd_party/include/ads \
               $$PWD/../3rd_party/include

# 编译中间文件
MOC_DIR     = ./tmp/moc
RCC_DIR     = ./tmp/rcc
UI_DIR      = ./tmp/ui
OBJECTS_DIR = ./tmp/obj

SOURCES += \
        main.cpp

# 程序信息
CONFIG += skip_target_version_ext #避免dll名称中出现数字
# 版本
VERSION = 1.0.0
# 图标
RC_ICONS = panda.ico #dll没有图标
# 公司名称
QMAKE_TARGET_COMPANY = "jackeylea.com"
# 产品名称
QMAKE_TARGET_PRODUCT = "VAPS XT"
# 文件说明
QMAKE_TARGET_DESCRIPTION = "Based on Qt 5.15.2 (MSVC 2019, x64)"
# 版权
QMAKE_TARGET_COPYRIGHT = "jackeylea © 2025.All rights reserved."
# 简体中文
RC_LANG = 0x0004

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
