#include "qconnection.h"

Qconnection::Qconnection(QQueue<QByteArray> *protocollist, QMutex *mutex)
{
    this->protocollist = protocollist;
    this->mutex = mutex;
    debug = false;
    connect(this,SIGNAL(readyRead()),this,SLOT(readyforready()));
}
void Qconnection::readyforready(){
    readbuffer = readAll();
    int count = readbuffer.count();
    for(int i=0;i<count;i++){
        if((unsigned char)readbuffer.at(i)==0xFE){
           protocoldata.clear();
        }else if((unsigned char)readbuffer.at(i)== 0xFF){
            mutex->lock();
            protocollist->enqueue(protocoldata);
            //qDebug()<<kor(protocoldata);
            mutex->unlock();

        }else {
            protocoldata.append(readbuffer.at(i));
        }
    }
}
