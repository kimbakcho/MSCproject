#include "tjango_th.h"

tjango_th::tjango_th(xing *x1, Tcpserverframe *tmf)
{
    m_stopflag = true;
    playtime_flag = true;
    this->x1 = x1;
    this->tmf = tmf;
}
void tjango_th::run(){
    while(m_stopflag){
        QByteArray qt_temp[10];
        t0424InBlockdata data;
        qt_temp[0] =  tmf->QEjaccnumber->text().toLocal8Bit();
        data.accno = qt_temp[0].data();

        qt_temp[1] = tmf->QEjpwumber->text().toLocal8Bit();
        data.passwd = qt_temp[1].data();

        qt_temp[2] = QString("").toLocal8Bit();
        data.charge = qt_temp[2].data();

        qt_temp[3] = QString("").toLocal8Bit();
        data.cts_expcode = qt_temp[3].data();
        qt_temp[4] = QString("").toLocal8Bit();
        data.dangb = qt_temp[4].data();
        qt_temp[5] = QString("").toLocal8Bit();
        data.prcgb = qt_temp[5].data();
        qt_temp[6] = QString("").toLocal8Bit();
        data.chegb = qt_temp[6].data();
        x1->t0424_Request(true,data);

        QByteArray qt_temp_0425[10];
        t0425InBlockdata data_0425;
        qt_temp_0425[0] =  tmf->QEjaccnumber->text().toLocal8Bit();
        data_0425.accno = qt_temp_0425[0].data();
        qt_temp_0425[1] = tmf->QEjpwumber->text().toLocal8Bit();
        data_0425.passwd = qt_temp_0425[1].data();
        qt_temp_0425[2] = QString("").toLocal8Bit();
        data_0425.expcode = qt_temp_0425[2].data();
        qt_temp_0425[3] = QString("2").toLocal8Bit();
        data_0425.chegb = qt_temp_0425[3].data();
        qt_temp_0425[4] = QString("0").toLocal8Bit();
        data_0425.medosu = qt_temp_0425[4].data();
        qt_temp_0425[5] = QString("1").toLocal8Bit();
        data_0425.sortgb = qt_temp_0425[5].data();
        qt_temp_0425[6] = QString(" ").toLocal8Bit();
        data_0425.cts_ordno = qt_temp_0425[6].data();
        x1->t0425_Request(true,data_0425);
        msleep(1500);
    }
}
