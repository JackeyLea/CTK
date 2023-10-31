#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDirIterator>
#include <QDebug>

#include <ctkPluginFrameworkLauncher.h>
#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

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

}

