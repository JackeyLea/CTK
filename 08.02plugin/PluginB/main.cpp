#include "widgeta.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetA w;
    w.show();
    return a.exec();
}
