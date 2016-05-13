#ifndef QTICHDATA_H
#define QTICHDATA_H

#include <QObject>
#include <QString>
#include <QTime>

class Qrichdata
{

public:
    explicit Qrichdata();
    QString hname;
    QString price;
    QString loss;
    QString obj;
    QString shcode;
    QString str_price_result;
    QString str_obj1_result;
    QString str_loss_result;
    bool loss_flag;
    bool obj_flag;
    bool init_priceflag;
    bool first_jong;
    bool calok;
    bool buyuse;
    bool limittimeflag;
    bool limittimeflag_enter;
    int limittimesec;
    QTime buytime;
    QTime limittime;



signals:

public slots:
};

#endif // QTICHDATA_H
