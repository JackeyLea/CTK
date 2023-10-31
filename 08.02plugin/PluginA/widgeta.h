#ifndef WIDGETA_H
#define WIDGETA_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetA; }
QT_END_NAMESPACE

class WidgetA : public QWidget
{
    Q_OBJECT

public:
    WidgetA(QWidget *parent = nullptr);
    ~WidgetA();

private:
    Ui::WidgetA *ui;
};
#endif // WIDGETA_H
