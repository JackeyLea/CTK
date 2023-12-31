#ifndef PLUGINSERVICE_H
#define PLUGINSERVICE_H

#include <QWidget>

class PluginService
{
public:
    virtual ~PluginService(){}
    virtual void doSomething() = 0;
    virtual QWidget* getWidget() = 0;
};

#define PluginService_iid "org.commontk.service.demos.PluginService"
Q_DECLARE_INTERFACE(PluginService,PluginService_iid)

#endif // PLUGINSERVICE_H
