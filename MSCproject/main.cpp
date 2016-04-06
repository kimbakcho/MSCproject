#include "widget.h"
#include "loginwiget.h"
#include <QApplication>
#include <xing.h>
#include <QVector>
#include <QMap>
#include <qrichdata.h>
#include <qprotocaltheard.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QVector<QByteArray> *protocollist;
    protocollist = new QVector<QByteArray>();
    QMap<QString,Qrichdata> *richdata = new QMap<QString,Qrichdata>();
//    Widget w;
//    w.show();
    xing *x1;
    x1 = new xing();
    if(x1->init()){
        if(x1->ETK_Connect(0)){

        }else{
            qDebug()<<kor("접속 실패");
        }

    }else{
         qDebug()<<kor("초기화 실패");
    }
    Tcpserverframe *tmf = new Tcpserverframe(protocollist);
    Loginwiget *login = new Loginwiget(x1,tmf);
    login->show();

    qprotocaltheard *protocalth = new qprotocaltheard(protocollist,richdata);
    protocalth->start();

    return a.exec();
}
