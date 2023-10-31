#include "widgeta.h"
#include "ui_widgeta.h"

WidgetA::WidgetA(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetA)
{
    ui->setupUi(this);
}

WidgetA::~WidgetA()
{
    delete ui;
}

