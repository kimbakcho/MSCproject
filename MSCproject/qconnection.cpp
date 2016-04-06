#include "qconnection.h"

Qconnection::Qconnection(QVector<QByteArray> *protocollist)
{
    this->protocollist = protocollist;
    connect(this,SIGNAL(readyRead()),this,SLOT(readyforready()));
}
void Qconnection::readyforready(){
    readbuffer = readAll();
    int count = readbuffer.count();

    for(int i=0;i<count;i++){
        if((unsigned char)readbuffer.at(i)==0xAA){
           protocoldata.clear();
        }else if((unsigned char)readbuffer.at(i)== 0xAB){
            protocollist->append(protocoldata);
        }else {
            protocoldata.append(readbuffer.at(i));
        }
    }
}
