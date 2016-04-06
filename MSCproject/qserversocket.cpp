#include "qserversocket.h"

QServersocket::QServersocket(int port,QVector<QByteArray> *protocollist)
{
    this->protocollist = protocollist;
    listen(QHostAddress::Any,port);
}

void QServersocket::incomingConnection(int socketDescriptor){
    Qconnection *connection = new Qconnection(protocollist);
    connection->setSocketDescriptor(socketDescriptor);


}
