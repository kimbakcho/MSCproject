#include "qprotocaltheard.h"

qprotocaltheard::qprotocaltheard(QVector<QByteArray> *protocollist,QMap<QString,Qrichdata> *richdata)
{
    this->protocollist = protocollist;
    this->richdata = richdata;
    runflag = true;
}

void qprotocaltheard::run(){
    while(runflag){
        while(!protocollist->isEmpty()){
            QString data = QString(protocollist->takeFirst());
            qDebug()<<data;
        }
    }
}
