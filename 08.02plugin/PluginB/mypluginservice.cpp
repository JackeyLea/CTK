#include "mypluginservice.h"

#include <ctkPluginContext.h>
#include <QDebug>
#include "widgetb.h"

MyPluginService::MyPluginService(ctkPluginContext *context)
    :m_pContext(context)
{
    context->registerService<PluginService>(this);
}

void MyPluginService::doSomething()
{
    qDebug() << "Plugin B";
}

QWidget *MyPluginService::getWidget()
{
    return new WidgetB;
}
