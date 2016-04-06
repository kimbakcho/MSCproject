#include "qsettingframe.h"
QSettingframe::QSettingframe(QTcsocket *tcsocket,QVector<webwiget*> *vecweb,QWidget *parent) : QWidget(parent)
{
    this->tcsocket = tcsocket;
    this->vecweb = vecweb;
    QLSetip = new QLabel("Setip");
    QEsetip = new QLineEdit();
    QLSetport = new QLabel("Setport");
    QEsetport = new QLineEdit();
    Qstartbutton = new QPushButton("\nstart\n");
    gridlayout = new QGridLayout();
    QLwebwigetcount = new QLabel("Setcount");
    QEwebwigetcount = new QLineEdit();

    gridlayout->addWidget(QLSetip,0,0);
    gridlayout->addWidget(QEsetip,0,1);
    gridlayout->addWidget(QLSetport,1,0);
    gridlayout->addWidget(QEsetport,1,1);
    gridlayout->addWidget(Qstartbutton,0,2,2,1);
    gridlayout->addWidget(QLwebwigetcount,2,0);
    gridlayout->addWidget(QEwebwigetcount,2,1);



    setLayout(gridlayout);

    //--read---
    QSettings settings1("config.ini",QSettings::IniFormat);
    settings1.beginGroup("setting");
    QEsetip->setText(settings1.value("serverip").toByteArray());
    QEsetport->setText(settings1.value("serverport").toByteArray());
    QEwebwigetcount->setText(settings1.value("webwigetcount").toByteArray());
    settings1.endGroup();
    //---------


    connect(QEsetip,SIGNAL(textEdited(QString)),this,SLOT(QEsetip_change(QString)));
    connect(QEsetport,SIGNAL(textEdited(QString)),this,SLOT(QEsetport_change(QString)));
    connect(Qstartbutton,SIGNAL(clicked(bool)),this,SLOT(Qstartbutton_push()));
    connect(QEwebwigetcount,SIGNAL(textEdited(QString)),this,SLOT(QEwebwigetcount_change(QString)));
    if(QEwebwigetcount->text().compare("")==0){
       QEwebwigetcount->setText("1");
    }

}
void QSettingframe::QEsetip_change(QString str){
    //write setting--------------------------------------------
    QSettings settings2("config.ini",QSettings::IniFormat);
    settings2.beginGroup("setting");
    settings2.setValue("serverip",str.toLocal8Bit());
    settings2.endGroup();
    //---------------------------------------------------------

}
void QSettingframe::QEsetport_change(QString str){
    //write setting--------------------------------------------
    QSettings settings2("config.ini",QSettings::IniFormat);
    settings2.beginGroup("setting");
    settings2.setValue("serverport",str.toLocal8Bit());
    settings2.endGroup();
    //---------------------------------------------------------
}
void QSettingframe::QEwebwigetcount_change(QString str){
    //write setting--------------------------------------------
    QSettings settings2("config.ini",QSettings::IniFormat);
    settings2.beginGroup("setting");
    settings2.setValue("webwigetcount",str.toLocal8Bit());
    settings2.endGroup();
    //---------------------------------------------------------

}

void QSettingframe::Qstartbutton_push(){
    if(tcsocket==NULL){
        tcsocket = new QTcsocket(QEsetip->text(),QEsetport->text().toInt());
    }
    for(int i=0;i<QEwebwigetcount->text().toInt();i++){
         webwiget *tempwebbiget = new webwiget();
         vecweb->append(tempwebbiget);
         //tempwebbiget->show();
         tempwebbiget->autostep();
    }
}
