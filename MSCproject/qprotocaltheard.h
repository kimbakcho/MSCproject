#ifndef QPROTOCALTHEARD_H
#define QPROTOCALTHEARD_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <QDebug>
#include <qrichdata.h>
#include <QMap>
#include <QString>
#include <QTime>
#include <QTextCodec>
#include <xing.h>
#include <tcpserverframe.h>
#include <QQueue>
#define kor(str) QString::fromLocal8Bit(str)

class qprotocaltheard : public QThread
{
    Q_OBJECT
public:
    explicit qprotocaltheard(QQueue<QByteArray> *protocollist, QMap<QString, Qrichdata *> *richdata
                             , QMap<QString, QString> *shcodemap, xing *x1, Tcpserverframe *tmf);
    QQueue<QByteArray> *protocollist;
    QMap<QString,Qrichdata *> *richdata;
    QTime time;
    bool runflag;
    QTextCodec *codec;
    QMap<QString,QString> *shcodemap;
    QTime reply_time;
    QString reply_timeh;
    QString reply_timem;
    QByteArray data;
    QString data_str;
    QString timestr;
    QString fromdata;
    QStringList fromlist;
    xing *x1;
    QByteArray qb_temp[10];
    CSPAT00600data data060;
    QString price;
    QString tpcode;
    QString prcptncode;
    QString mgntrncode;
    QString loandt;
    QString ordcnditpcode;
    QString ju_count;
    int real_price;
    int real_money;
    int total_ordqty;
    double price_double;
    double per1;
    double per3;
    double price_double_result;
    double obj1_double;
    double loss_double;

    int price_reslut;
    int obj1_result;
    int loss_result;

    QString str_price_result;
    QString str_obj1_result;
    QString str_loss_result;

    QString real_tranding;



    Tcpserverframe *tmf;
    QString shcodedata;

private:
    void run();

signals:

public slots:
};

#endif // QPROTOCALTHEARD_H
