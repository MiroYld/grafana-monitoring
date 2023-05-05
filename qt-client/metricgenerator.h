#ifndef METRICGENERATOR_H
#define METRICGENERATOR_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QRandomGenerator>
#include <QTimer>

#include "clienttelegraf.h"

class MetricGenerator : public QObject
{
    Q_OBJECT

public:
    void sendMetrics();

private:
    ClientTelegraf _client_telegraf{};
};


#endif // METRICGENERATOR_H
