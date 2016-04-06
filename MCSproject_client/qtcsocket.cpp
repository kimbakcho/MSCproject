#include "qtcsocket.h"

QTcsocket::QTcsocket(QString ip,int port)
{
    this->ip=ip;
    this->port=port;
    connecttimer = new QTimer();
    QHostAddress address(ip);
    connectToHost(address,port);
    connecttimer->setInterval(1000);
    connecttimer->start();
    connect(connecttimer,SIGNAL(timeout()),this,SLOT(timeout_connectcheck()));
}
void QTcsocket::timeout_connectcheck(){
    if(state()!=QAbstractSocket::ConnectedState){
        QHostAddress address(ip);
        connectToHost(address,port);
    }
}


