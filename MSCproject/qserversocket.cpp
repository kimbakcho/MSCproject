#include "qserversocket.h"

QServersocket::QServersocket(QObject *parent) : QObject(parent)
{
   listen(QHostAddress::Any,20005);
}

void QServersocket::incomingConnection(int socketDescriptor){
    QTcpSocket *connection = new QTcpSocket();
    connection->setSocketDescriptor(socketDescriptor);


}
