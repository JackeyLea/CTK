#include "pluginactivator.h"
#include "mypluginservice.h"

void PluginActivator::start(ctkPluginContext *context)
{
    ps.reset(new MyPluginService(context));
}

void PluginActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)
}
