#include "qserversocket.h"

QServersocket::QServersocket(int port,QQueue<QByteArray> *protocollist,QVector<Qconnection *> *socketllist,QLabel *count)
{
    this->protocollist = protocollist;
    this->socketllist = socketllist;
    this->count = count;
    join_count=0;
    listen(QHostAddress::Any,port);
}

void QServersocket::incomingConnection(int socketDescriptor){
    Qconnection *connection = new Qconnection(protocollist);
    connection->setSocketDescriptor(socketDescriptor);
    socketllist->append(connection);
    join_count++;
    count->setText(QString("%1").arg(join_count));
}
