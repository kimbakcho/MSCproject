#include "widget.h"
#include "loginwiget.h"
#include <QApplication>
#include <xing.h>
#include <QQueue>
#include <QMap>
#include <qrichdata.h>
#include <qprotocaltheard.h>
#include <QFile>
#include <tjango_th.h>
#include <tpricemoniter.h>
#include <QMutex>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQueue<QByteArray> *protocollist;

    protocollist = new QQueue<QByteArray>();
    QMap<QString,Qrichdata *> *richdata = new QMap<QString,Qrichdata *>();
    QMap<QString,QString> *shcodemap = new QMap<QString,QString>;
    QMutex *mutex;
    mutex = new QMutex();
//    Widget w;
//    w.show();
    xing *x1;
    QFile *file;
    file = new QFile();
    QString filename;
    filename = "C:\\shcodedata.txt";
    file->setFileName(filename);
    file->open(QIODevice::ReadOnly);
    QStringList shcode_result;
    QTextStream read(file);
    while(!read.atEnd()){
        QString temp = read.readLine();
        shcode_result = temp.split(",");
        shcodemap->insert(shcode_result.at(0),shcode_result.at(1));
    }
    Tcpserverframe *tmf = new Tcpserverframe(protocollist,mutex);
    x1 = new xing(richdata,tmf);
    if(x1->init()){
        if(x1->ETK_Connect(1)){

        }else{
            qDebug()<<kor("접속 실패");
        }

    }else{
         qDebug()<<kor("초기화 실패");
    }

    Loginwiget *login = new Loginwiget(x1,tmf);
    login->show();

    qprotocaltheard *protocalth = new qprotocaltheard(protocollist,richdata,shcodemap,x1,tmf,mutex);
    protocalth->start();

    tjango_th *jangoth  = new tjango_th(x1,tmf);
    jangoth->start();

    tpricemoniter *tprice = new tpricemoniter(x1,richdata);
    tprice->start();



    return a.exec();
}
