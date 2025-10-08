#include "widgetb.h"
#include "ui_widgetb.h"

WidgetB::WidgetB(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetB)
{
    ui->setupUi(this);
}

WidgetB::~WidgetB()
{
    delete ui;
}


void WidgetB::on_btnClear_clicked()
{
    ui->text->clear();
}

