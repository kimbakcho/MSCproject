#include "tcpserverframe.h"

Tcpserverframe::Tcpserverframe(QVector<QByteArray> *protocollist,QWidget *parent) : QWidget(parent)
{
    this->protocollist = protocollist;
    socketllist = new QVector<Qconnection *>;
    QLsetip = new QLabel("Set ip");
    QEsetip = new QLineEdit();
    QLsetport = new QLabel("Set port");
    QEsetport = new QLineEdit();
    QServerstart = new QPushButton("Server\n\nStart");
    Qremotestart  = new QPushButton("remote\n\nStart");
    Qremotestop = new QPushButton("remote\n\nStop");
    joincount = new QLabel("join count");
    joincount_data = new QLabel("0");
    mgridlayout = new QGridLayout();
    mgridlayout->addWidget(QLsetip,0,0);
    mgridlayout->addWidget(QEsetip,0,1);
    mgridlayout->addWidget(QLsetport,1,0);
    mgridlayout->addWidget(QEsetport,1,1);
    mgridlayout->addWidget(QServerstart,0,2,2,1);
    mgridlayout->addWidget(Qremotestart,2,2,2,1);
    mgridlayout->addWidget(Qremotestop,4,2,2,1);
    mgridlayout->addWidget(joincount,5,0);
    mgridlayout->addWidget(joincount_data,5,1);


    setLayout(mgridlayout);
    //--read---
    QSettings settings1("config.ini",QSettings::IniFormat);
    settings1.beginGroup("setting");
    QEsetport->setText(settings1.value("serverport").toByteArray());
    settings1.endGroup();
    //---------


    connect(QServerstart,SIGNAL(clicked(bool)),this,SLOT(serverstart()));
    connect(Qremotestart,SIGNAL(clicked(bool)),this,SLOT(remotestart()));
    connect(Qremotestop,SIGNAL(clicked(bool)),this,SLOT(remotestop()));
    connect(QEsetport,SIGNAL(textEdited(QString)),this,SLOT(QEsetport_change(QString)));


}
void Tcpserverframe::serverstart(){

    if(serversocket == NULL){
        int port = QEsetport->text().toInt();
        serversocket = new QServersocket(port,protocollist,socketllist,joincount_data);

    }
}
void Tcpserverframe::QEsetport_change(QString str){
    //write setting--------------------------------------------
    QSettings settings2("config.ini",QSettings::IniFormat);
    settings2.beginGroup("setting");
    settings2.setValue("serverport",str.toLocal8Bit());
    settings2.endGroup();
    //---------------------------------------------------------
}
void Tcpserverframe::remotestart(){
        Qconnection *tempcon = NULL;
        for(int i=0;i<socketllist->size();i++){
            tempcon = socketllist->at(i);
            tempcon->write("start");
            tempcon->flush();
        }
}
void Tcpserverframe::remotestop(){
    Qconnection *tempcon = NULL;
    for(int i=0;i<socketllist->size();i++){
        tempcon = socketllist->at(i);
        tempcon->write("stop");
        tempcon->flush();
    }
}
