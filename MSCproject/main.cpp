#include "widget.h"
#include "loginwiget.h"
#include <QApplication>
#include <xing.h>
#include <QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QVector<QByteArray> *protocollist;
    protocollist = new QVector<QByteArray>();
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
    Tcpserverframe *tmf = new Tcpserverframe();
    Loginwiget *login = new Loginwiget(x1,tmf);
    login->show();





    return a.exec();
}
