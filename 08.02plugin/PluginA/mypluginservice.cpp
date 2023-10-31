#include "mypluginservice.h"

#include <ctkPluginContext.h>
#include <QDebug>
#include "widgeta.h"

MyPluginService::MyPluginService(ctkPluginContext *context)
    :m_pContext(context)
{
    context->registerService<PluginService>(this);
}

void MyPluginService::doSomething()
{
    qDebug() << "Plugin A";
}

QWidget *MyPluginService::getWidget()
{
    return new WidgetA;
}
