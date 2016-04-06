#include "webwiget.h"

webwiget::webwiget(QTcsocket *tcsocket)
{
    timer = new QTimer();
    load(QUrl("http://rich-stock.com/"));
    qwf = this->page()->mainFrame();
    this->tcsocket = tcsocket;
    connect(this,SIGNAL(loadFinished(bool)),this,SLOT(finishedpage(bool)));
    connect(timer,SIGNAL(timeout()),this,SLOT(sitemoniter()));
    findstr1 =kor("매수가");
    findstr2 =kor("손절가");
    findstr3 =kor("1차목표");
    findstr4 =kor("대응");

    siteplaycount = 0;
    tempsitecount = 0;
    urllastsite="http://rich-stock.com";
    vipcheck = false;

    timer->setInterval(20000);
    timer->start();


}

void webwiget::autostep(){
    QNetworkRequest requ;
    requ.setUrl(QUrl("http://rich-stock.com/member/log_in_ok.asp"));
    requ.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    QByteArray postdata_2;
    postdata_2.append("M_ID=vngkgk624&M_Password=super624");
    load(requ,QNetworkAccessManager::PostOperation,postdata_2);
}

void webwiget::finishedpage(bool flag){
//    if(mf != NULL){
//        vipcheck = mf->Qsitevipcheck->isChecked();
//    }
    if(vipcheck){
        findstr1 =kor("[신규 추천 종목]");
        findstr2 =kor("목표가");
        findstr3 =kor("매수");
        findstr4 =kor("비중");
    }
    QString str = this->url().toString();
    int str_result= str.indexOf("&b_url=contents&list_no=");
    int str_result_1 = str.indexOf("&b_url=list&category=freer_1");
    int str_result_2 = str.indexOf("index.asp");
    siteplaycount++;
    urllastsite = str;

    qDebug()<<kor("site = %1").arg(str);
    if(str.compare("about:blank")==0){
        urllastsite = "http://rich-stock.com";
    }

    if(flag && (str_result!= -1)){
        document = qwf->documentElement();
        QWebElementCollection result_1;
        QWebElementCollection time_result_1;
        QWebElement result_2;
        QWebElement time_result_2;
        QString str_result;
        QString time_str_result;
        QStringList strlist_result;
        int reusult_4[4];
        QStringList pricesplit;
        QString pricetemp;
        QString Cpricetemp;
        QStringList losspricesplit;
        QString losspricetemp;
        QString Closspricetemp;
        QStringList objpricesplit;
        QString objpricetemp;
        QString Cobjpricetemp;
        result_1 = document.findAll(".re_comment dl dd TEXTAREA");
        for(int i=0;i<result_1.count();i++){
            result_2 = result_1.at(i);
            str_result= result_2.toPlainText();
            reusult_4[0] =str_result.indexOf(findstr1);
            reusult_4[1] =str_result.indexOf(findstr2);
            reusult_4[2] =str_result.indexOf(findstr3);
            reusult_4[3] =str_result.indexOf(findstr4);
            if((reusult_4[0] != -1)&&(reusult_4[1] != -1)&&(reusult_4[2] != -1)&&(reusult_4[3] != -1)){
                if(vipcheck){
                    strlist_result =  str_result.split("\n\n");
                }else {
                    strlist_result =  str_result.split("\t");
                }
                time_result_1 = document.findAll(".re_comment dl dt");
                time_result_2 = time_result_1.at(i);
                time_str_result = time_result_2.toPlainText();
                QStringList time_result_3 = time_str_result.split(" ");
                QString time_result_4 = time_result_3.at(2);
                QString time_result_5 = time_result_4.mid(0,5);
                QStringList time_result_6 = time_result_5.split(":");
                QString reply_timeh = time_result_6.at(0);
                QString reply_timem = time_result_6.at(1);

                QString hname_temp;
                if(vipcheck){
                    QString temp_result1 = strlist_result.at(1);
                    QStringList temp_result1_list = temp_result1.split(" ");
                    hname_temp = temp_result1_list.at(0);
                    pricetemp = temp_result1_list.at(1);
                }else{
                    hname_temp = strlist_result.at(0);
                }
                if(!vipcheck){
                    pricetemp = strlist_result.at(2);
                    pricesplit = pricetemp.split(kor("원"));
                    Cpricetemp = pricesplit.at(0);
                    losspricetemp = strlist_result.at(4);
                    losspricesplit = losspricetemp.split(kor("원"));
                    Closspricetemp = losspricesplit.at(0);
                    objpricetemp = strlist_result.at(6);
                    objpricesplit = objpricetemp.split(kor("원"));
                    Cobjpricetemp = objpricesplit.at(0);
                }else {
                    pricesplit = pricetemp.split(kor("원"));
                    Cpricetemp = pricesplit.at(0);
                    Cpricetemp.replace(",","");
                    double d_price = Cpricetemp.toDouble();
                    double d_loss = d_price - (d_price*0.015);
                    int i_loss = (int)d_loss;
                    Closspricetemp = QString("%1").arg(i_loss);
                    double d_obj = d_price + (d_price*0.015);
                    int i_obj = (int)d_obj;
                    Cobjpricetemp = QString("%1").arg(i_obj);
                }
                if(vipcheck){
                    qDebug()<<kor("vip not contain name : %1 price : %2 loos : %3 1ob : %4 timeh = %5 timem = %6 ")
                              .arg(hname_temp).arg(Cpricetemp).arg(Closspricetemp).arg(Cobjpricetemp).arg(reply_timeh).arg(reply_timem);
                    qDebug()<<kor("----------------------------------------");
                }else{
                    if(tcsocket != NULL){
                        if(tcsocket->state()==QTcpSocket::ConnectedState){

                            QString senddata = kor("free,hname,%1,price,%2,loos,%3,1ob,%4,timeh,%5,timem,%6")
                                                          .arg(hname_temp).arg(Cpricetemp).arg(Closspricetemp).arg(Cobjpricetemp).arg(reply_timeh).arg(reply_timem);
                            QByteArray result_send_data;
                            result_send_data.append(0xAA);
                            result_send_data.append(senddata);
                            result_send_data.append(0xAB);
                            tcsocket->write(result_send_data);
                            tcsocket->flush();
                        }
                    }
                    qDebug()<<kor("free not contain name : %1 price : %2 loos : %3 1ob : %4 shcode = %5 time = %6 ")
                              .arg(hname_temp).arg(Cpricetemp).arg(Closspricetemp).arg(Cobjpricetemp).arg(reply_timeh).arg(reply_timem);
                    qDebug()<<kor("----------------------------------------");
                }
            }
        }
        load(QUrl(str));
    }else if(flag && (str_result_1 != -1) && !vipcheck){
        QWebElementCollection index_result_1;
        QWebElement index_result_2;
        QString index_result_3;
        QStringList index_result_4;
        int daycompare[3];
        document = qwf->documentElement();
        index_result_1 = document.findAll(".table_board tr td a");
        index_result_2 = index_result_1.at(1);
        index_result_3= index_result_2.toPlainText();
        if(index_result_3.compare("")!=0){
            index_result_3.replace(kor("년"),",");
            index_result_3.replace(kor("월"),",");
            index_result_3.replace(kor("일"),",");
            index_result_3.replace(" ","");
            index_result_3.replace(kor("■"),"");
            index_result_4 = index_result_3.split(",");
            get_date = QDate::currentDate();
            daycompare[0] =2000+((QString)index_result_4.at(0)).toInt();
            daycompare[1] =((QString)index_result_4.at(1)).toInt();
            daycompare[2] =((QString)index_result_4.at(2)).toInt();
            QString link_url = index_result_1.at(1).attribute("href");
            QString link_go = QString("http://rich-stock.com/freer/%1").arg(link_url);


            if((daycompare[0] == get_date.year())&&
                    (daycompare[1] == get_date.month()) &&
                    (daycompare[2] == get_date.day())){
                    load(QUrl(link_go));
            }else{
                    load(QUrl("http://rich-stock.com/freer/?p_url=freer_1&B_Name=center&b_dir=talkclub&b_url=list&category=freer_1"));
            }
        }else {
            load(QUrl("http://rich-stock.com/freer/?p_url=freer_1&B_Name=center&b_dir=talkclub&b_url=list&category=freer_1"));
        }

    }else if(flag && (str_result_2!= -1) && !vipcheck){
        load(QUrl("http://rich-stock.com/freer/?p_url=freer_1&B_Name=center&b_dir=talkclub&b_url=list&category=freer_1"));
    }else if(flag && (str_result_2!= -1) && vipcheck){
        QWebElementCollection index_result_1;
        QWebElement index_result_2;
        QString index_result_3;
        QStringList index_result_4;
        int daycompare[3];
        document = qwf->documentElement();
        index_result_1 = document.findAll(".main_board_wrap tr td a");
        index_result_2 = index_result_1.at(0);
        index_result_3= index_result_2.toPlainText();
        if(index_result_3.compare("")!=0){
            index_result_3.replace(kor("년"),",");
            index_result_3.replace(kor("월"),",");
            index_result_3.replace(kor("일"),",");
            index_result_3.replace(" ","");
            index_result_3.replace(kor("■"),"");
            index_result_4 = index_result_3.split(",");
            get_date = QDate::currentDate();
            daycompare[0] =2000+((QString)index_result_4.at(0)).toInt();
            daycompare[1] =((QString)index_result_4.at(1)).toInt();
            daycompare[2] =((QString)index_result_4.at(2)).toInt();
            QString link_url = index_result_1.at(0).attribute("href");
            QStringList link_url_value = link_url.split("&");
            QString result_link_url = link_url_value.at(5);
            QString link_go = QString("http://rich-stock.com/freer/?dir_in=&p_url=freer_1&B_Name=center&b_dir=talkclub&category=freer_1&search=&searchstring=&b_url=contents&%1").arg(result_link_url);

            if((daycompare[0] == get_date.year())&&
                    (daycompare[1] == get_date.month()) &&
                    (daycompare[2] == get_date.day())){
                    load(QUrl(link_go));
            }else{
                    load(QUrl("http://rich-stock.com/index.asp"));
            }
        }else {
            load(QUrl("http://rich-stock.com/index.asp"));
        }
    }else if(!flag) {
        load(QUrl(str));
    }
}
void webwiget::sitemoniter(){
    if(tempsitecount==siteplaycount){
         load(QUrl(urllastsite));
    }else {
        tempsitecount=siteplaycount;
    }
}
