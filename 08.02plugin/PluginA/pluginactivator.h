#ifndef PLUGINACTIVATOR_H
#define PLUGINACTIVATOR_H

#include <QObject>
#include <QScopedPointer>

#include <ctkPluginActivator.h>
#include "../MainApp/pluginservice.h"

class PluginActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "PluginA_CTK")

public:
    void start(ctkPluginActivator* context);
    void stop(ctkPluginActivator* context);

private:
    QScopedPointer<PluginService> ps;
};

#endif // PLUGINACTIVATOR_H
