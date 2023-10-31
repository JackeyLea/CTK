#ifndef WIDGETB_H
#define WIDGETB_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetB; }
QT_END_NAMESPACE

class ctkPluginContext;
class WidgetB : public QWidget
{
    Q_OBJECT

public:
    WidgetB(QWidget *parent = nullptr);
    ~WidgetB();

private slots:
    void on_btnClear_clicked();

private:
    Ui::WidgetB *ui;
};
#endif // WIDGETB_H
