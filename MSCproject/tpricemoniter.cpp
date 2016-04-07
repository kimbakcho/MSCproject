#include "tpricemoniter.h"

tpricemoniter::tpricemoniter(xing *x1,QMap<QString,Qrichdata *> *richdata)
{
    m_stopflag = true;
    this->richdata = richdata;
    this->x1 = x1;
}
void tpricemoniter::run(){
    while(m_stopflag){
        mapkeylist = richdata->keys();
        int count = mapkeylist.count();
         for(int i=0;i<count;i++){
             QString key = mapkeylist.at(i);
             QByteArray qt_temp;
             t1101InBlockdata data;
             qt_temp = QString(key).toLocal8Bit();
             data.shcode = qt_temp.data();
             x1->t1101_Request(true,data);
             msleep(300);
         }
         if(count == 0){
             msleep(100);
         }
    }
}
