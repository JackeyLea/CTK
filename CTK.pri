win32:{
    BaseDir = D:/JackeyLea/vcpkg/installed/x64-windows/
    INCLUDEPATH += $$BaseDir/include/ctk \
                $$BaseDir/include/ctk/Libs/Core \
                $$BaseDir/include/ctk/Libs/PluginFramework \
                $$BaseDir/include/ctk/Libs/Widgets
    LIBS += -L$$BaseDir/lib/ -lCTKCore -lCTKPluginFramework
}
unix:{
    BaseDir = /home/jackey/Downloads/CTK-2023.07.13
    INCLUDEPATH += $$BaseDir/Libs/Core \
                    $$BaseDir/Libs/PluginFramework \
                    $$BaseDir/build/CTK-build/Libs/PluginFramework \
                    $$BaseDir/build/CTK-build/Libs/Core

    LIBS += -L$$BaseDir/build/CTK-build/bin \
            -lCTKCore -lCTKPluginFramework
}
