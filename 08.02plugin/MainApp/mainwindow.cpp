#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDirIterator>
#include <QDebug>

#include <ctkPluginFrameworkLauncher.h>
#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

#include "pluginservice.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadPlugin();
}

MainWindow::~MainWindow()
{
    ctkPluginFrameworkLauncher::stop();

    delete ui;
}

void MainWindow::loadPlugin()
{
    //获取插件位置
    QString path = QApplication::applicationDirPath() + "/plugins";

    //将插件位置添加到搜索路径列表
    ctkPluginFrameworkLauncher::addSearchPath(path);

    //设置并启动CTK插件系统
    ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");

    //获取插件上下文
    context = ctkPluginFrameworkLauncher::getPluginContext();

    //处理目录中的每一个插件
    QDirIterator itPlugin(path,QStringList() << "*.dll" <<"*.so",QDir::Files);
    while(itPlugin.hasNext()){
        //获取当前插件完整路径
        QString strPlugin = itPlugin.next();

        try{
            //安装插件
            QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(strPlugin));

            //获取符号名
            QString symb = plugin->getSymbolicName();
            qDebug()<<"Symbolic Name: "<<symb;

            //启动插件
            plugin->start(ctkPlugin::START_TRANSIENT);
            qDebug()<<"Plugin start ...";

            //将插件所指向的界面添加到主界面
            ctkServiceReference reference = context->getServiceReference<PluginService>();
            if(reference){
                PluginService* service = qobject_cast<PluginService*>(context->getService(reference));
                if(service != Q_NULLPTR){
                    service->doSomething();

                    QWidget* w = service->getWidget();
                    if("Plugin.A" == symb){
                        ui->glPluginA->addWidget(w);
                    }else if("Plugin.B"==symb){
                        ui->glPluginB->addWidget(w);
                    }
                }
            }
        }catch(const ctkPluginException &e){
            qDebug()<<"Failed to install plugin"<<e.what();
            return;
        }
    }
}

