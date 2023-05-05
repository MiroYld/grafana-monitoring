#ifndef CLIENTTELEGRAF_H
#define CLIENTTELEGRAF_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QQueue>
#include <QJsonDocument>

class ClientTelegraf : public QObject {

    Q_OBJECT

public:
    explicit ClientTelegraf(QObject *parent = nullptr);
    void sendData(const QJsonDocument &doc);

private:
    QTcpSocket *_socket{};
    QQueue<QJsonDocument> _queueMetric{};
    QString _url_telegraf{};
    int _port_telegraf{};
};

#endif // CLIENTTELEGRAF_H
