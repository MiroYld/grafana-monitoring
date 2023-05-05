#include "metricgenerator.h"

void MetricGenerator::sendMetrics()
{
    QTimer::singleShot(5000,this,&MetricGenerator::sendMetrics);

    const QString metric = "humidity";
    int cardNumber = QRandomGenerator::global()->generate() % 2 + 1;
    float value = QRandomGenerator::global()->generate() % 101;

    QJsonObject metricObject;
    metricObject.insert("name", metric);
    metricObject.insert("card", QString::number(cardNumber));
    metricObject.insert("value", value);
    QJsonDocument doc(metricObject);

    _client_telegraf.sendData(doc);
}
