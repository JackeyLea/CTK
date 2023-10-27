#ifndef TESTPLUGINACTIVATOR_H
#define TESTPLUGINACTIVATOR_H

#include <QObject>

#include "ctkPluginActivator.h"
#include "ctkPluginContext.h"

class testPluginActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "testPlugin")
    Q_INTERFACES(ctkPluginActivator)
public:
    explicit testPluginActivator();
    void start(ctkPluginContext *context);
    void stop(ctkPluginContext *context);

signals:

};

#endif // TESTPLUGINACTIVATOR_H
