#include <QCoreApplication>
#include "metricgenerator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MetricGenerator generator;
    generator.sendMetrics();

    return a.exec();
}
