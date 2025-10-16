#include <QCoreApplication>
#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>
#include <QtDebug>
#include <QUrl>

QString static firstPlugin_filePath = "libtestPlugin.so";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ctkPluginFrameworkFactory frameworkFactory;
    //获取框架
    QSharedPointer<ctkPluginFramework> framework = frameworkFactory.getFramework();

    // 初始化并启动插件框架
    try {
        framework->init();
        framework->start();
        qDebug() << "CTK plugin framework start...";
    } catch (const ctkPluginException &e) {
        qDebug() << "CTK plugin framework init err: " << e.what();
        return -1;
    }

    // 获取插件服务的contex
    // ctkPluginContext* pluginContext = framework->getPluginContext();
    // try {
    //     // 安装插件
    //     QSharedPointer<ctkPlugin> plugin = pluginContext->installPlugin(QUrl::fromLocalFile(firstPlugin_filePath));
    //     qDebug() << QString("Plugin[%1_%2] installed...").arg(plugin->getSymbolicName()).arg(plugin->getVersion().toString());
    //     // 启动插件
    //     plugin->start(ctkPlugin::START_TRANSIENT);
    //     qDebug() << "Plugin start...";
    // } catch (const ctkPluginException &e) {
    //     qDebug() << QString("Failed install or run plugin: ") << e.what();
    //     return -2;
    // }

    return a.exec();
}
