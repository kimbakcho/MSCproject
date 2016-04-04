#include "widget.h"
#include "loginwiget.h"
#include <QApplication>
#include <xing.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
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
    Loginwiget *login = new Loginwiget(x1);
    login->show();


    return a.exec();
}
