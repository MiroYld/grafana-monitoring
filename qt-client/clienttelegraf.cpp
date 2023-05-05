#include "clienttelegraf.h"
#include <QJsonObject>

ClientTelegraf::ClientTelegraf(QObject *parent) : QObject(parent) {

    _socket = new QTcpSocket(this);
    _url_telegraf = qgetenv("URL_TELEGRAF");
    if(_url_telegraf.isEmpty()){
        qWarning()<< "env var PORT_TELEGRAF is empty default value : localhost";
        _url_telegraf = "localhost";
    }
    _port_telegraf = qEnvironmentVariableIntValue("PORT_TELEGRAF");
    if(_port_telegraf == 0){
        qWarning()<< "env var PORT_TELEGRAF is empty default value : 8080";

        _port_telegraf = 8080;
    }
    _socket->connectToHost(_url_telegraf, _port_telegraf); // connect to host

    if (!_socket->waitForConnected()) {
        qDebug() << "Impossible de se connecter à : " << _url_telegraf<<":"<<_port_telegraf << _socket->errorString();
    } else {
        qDebug() << "Connecté à : "<< _url_telegraf<<":"<<_port_telegraf;
    }
}
/**
 * @brief Sends a QJsonDocument containing metrics data to the Telegraf server
 *
 * If the connection is not available, metrics data are added to a queue until the connection is established again.
 *
 * @param doc The QJsonDocument containing metrics data
 */
void ClientTelegraf::sendData(const QJsonDocument &doc) {

    if(_socket == nullptr){
        _queueMetric.append(doc);
    }else{

        if (_socket->state() == QAbstractSocket::ConnectedState) {
            auto bytes = doc.toJson(QJsonDocument::Compact);
            qDebug()<< "sending : " << bytes;
            _socket->write(bytes + "\n");
            _socket->flush();
        } else {
            qWarning() << "Socket is not diconnected adding metrics on queue and try to reconnect";
            _queueMetric.append(doc);
            _socket->connectToHost(_url_telegraf, _port_telegraf);
        }
    }
}
