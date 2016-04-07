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
            QByteArray data = protocollist->takeFirst();
            QString data_str = QString(data);
            time = QTime::currentTime();
            QString timestr = time.toString("hh:mm:ss");
            qDebug()<<kor(data)<<timestr;

        }
    }
}
