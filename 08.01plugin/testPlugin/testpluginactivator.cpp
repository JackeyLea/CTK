#include "testpluginactivator.h"

#include <QDebug>

testPluginActivator::testPluginActivator()
{

}

void testPluginActivator::start(ctkPluginContext *context)
{
    qDebug() << "first plugin start: " << context;
}

void testPluginActivator::stop(ctkPluginContext *context)
{
    qDebug() << "first plugin stop: " << context;
}
