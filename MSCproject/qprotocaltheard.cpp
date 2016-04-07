#include "qprotocaltheard.h"

qprotocaltheard::qprotocaltheard(QVector<QByteArray> *protocollist, QMap<QString,Qrichdata *> *richdata,
                                QMap<QString,QString> *shcodemap, xing *x1,Tcpserverframe *tmf)
{
    this->protocollist = protocollist;
    this->richdata = richdata;
    this->shcodemap = shcodemap;
    runflag = true;
    this->x1 = x1;
    this->tmf = tmf;

}

void qprotocaltheard::run(){
    while(runflag){
        while(!protocollist->isEmpty()){
            data = protocollist->takeFirst();
            data_str = QString(data);
            time = QTime::currentTime();
            timestr = time.toString("hh:mm:ss");
            fromdata = kor(data);
            fromlist = fromdata.split(",");
            shcodedata=shcodemap->value(fromlist.at(2));
            if(!richdata->contains(shcodedata)){
                Qrichdata * temp_rich = new Qrichdata();
                temp_rich->hname = fromlist.at(2);
                temp_rich->shcode = shcodedata;
                temp_rich->price = fromlist.at(4);
                temp_rich->loss = fromlist.at(6);
                temp_rich->obj = fromlist.at(8);
                temp_rich->loss_flag=false;
                temp_rich->obj_flag=false;
                reply_timeh = fromlist.at(10);
                reply_timem = fromlist.at(12);
                reply_time.setHMS(reply_timeh.toInt(),reply_timem.toInt()+1,10);
                int i_reply_time = QTime(0,0,0).secsTo(reply_time);
                //¸Å¼ö
                price = temp_rich->price;
                tpcode = "2";
                prcptncode = "00";
                mgntrncode = "000";
                loandt ="";
                ordcnditpcode = "0";

                qb_temp[0] = temp_rich->shcode.toLocal8Bit();
                data060.strIsuNo = qb_temp[0].data();

                qb_temp[1] = tmf->QEjpwumber->text().toLocal8Bit();
                data060.strInptPwd = qb_temp[1].data();

                qb_temp[2] = tmf->QEjaccnumber->text().toLocal8Bit();
                data060.strAcntNo = qb_temp[2].data();

                //price qty
                real_price = price.toInt();
                real_money = tmf->QEjQLmoneyprice->text().toInt();
                total_ordqty  = real_money/real_price;
                ju_count.sprintf("%d",total_ordqty);
                qb_temp[3] = ju_count.toLocal8Bit();
                data060.strOrdQty = qb_temp[3].data();

                //price
                qb_temp[4] = price.toLocal8Bit();
                data060.strOrdPrc = qb_temp[4].data();

                //BnsTpCode
                qb_temp[5] = tpcode.toLocal8Bit();
                data060.strBnsTpCode = qb_temp[5].data();

                //OrdprcPtnCode
               qb_temp[6] = prcptncode.toLocal8Bit();
               data060.strOrdprcPtnCode = qb_temp[6].data();

               //MgntrnCode
              qb_temp[7] = mgntrncode.toLocal8Bit();
              data060.strMgntrnCode = qb_temp[7].data();

              //LoanDt
              qb_temp[8] = loandt.toLocal8Bit();
              data060.strLoanDt = qb_temp[8].data();

              //OrdCndiTpCode
             qb_temp[9] = ordcnditpcode.toLocal8Bit();
             data060.strOrdCndiTpCode = qb_temp[9].data();
             int result_3=0;
                 if(i_reply_time>=QTime(0,0,0).secsTo(time)){
                    result_3 = x1->CSPAT00600_Request(true,data060);
                 }else{
                     richdata->insert(temp_rich->shcode,temp_rich);
                     qDebug()<<fromdata<<timestr<<"missbuy";
                 }
             if(result_3){
                    richdata->insert(temp_rich->shcode,temp_rich);
                    qDebug()<<fromdata<<timestr<<"buy";
                    QByteArray qt_temp_1;
                    t1101InBlockdata data_1;
                    qt_temp_1 = QString(temp_rich->shcode).toLocal8Bit();
                    data_1.shcode = qt_temp_1.data();
                    x1->t1101_Request(true,data_1);
                }
            }
        }
    }
}

