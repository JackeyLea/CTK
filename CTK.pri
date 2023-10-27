win32:{

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
