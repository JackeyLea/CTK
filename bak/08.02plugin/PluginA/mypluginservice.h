#ifndef MYPLUGINSERVICE_H
#define MYPLUGINSERVICE_H

#include <QObject>

#include "../MainApp/pluginservice.h"

class ctkPluginContext;

class MyPluginService : public QObject, public PluginService
{
    Q_OBJECT
    Q_INTERFACES(PluginService)
public:
    MyPluginService(ctkPluginContext* context);
    void doSomething() override;
    QWidget* getWidget() override;

private:
    ctkPluginContext* m_pContext;
};

#endif // MYPLUGINSERVICE_H
