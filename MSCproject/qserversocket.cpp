#include "qserversocket.h"
#include <tcpserverframe.h>

QServersocket::QServersocket(int port, QQueue<QByteArray> *protocollist, QVector<Qconnection *> *socketllist, QLabel *count, QMutex *mutex,QObject *tmf)
{
    this->protocollist = protocollist;
    this->socketllist = socketllist;
    this->count = count;
    this->mutex= mutex;
    this->tmf = tmf;
    join_count=0;
    listen(QHostAddress::Any,port);
}

void QServersocket::incomingConnection(int socketDescriptor){
    Qconnection *connection = new Qconnection(protocollist,mutex);
    Tcpserverframe * tmf1 = (Tcpserverframe *)tmf;

    connection->setSocketDescriptor(socketDescriptor);
    QString ipdata = QString("ip = %1, port = %2").arg(connection->peerAddress().toString()).arg(connection->peerPort());
    socketllist->append(connection);
    join_count++;
    count->setText(QString("%1").arg(join_count));
    tmf1->iplistmodel->insertRow(tmf1->iplistmodel->rowCount());
    tmf1->iplistmodel->setData(tmf1->iplistmodel->index(tmf1->iplistmodel->rowCount()-1,0),ipdata);

}
