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


void WidgetA::on_btnClear_clicked()
{
    ui->text->clear();
}

