#ifndef TJANGO_TH_H
#define TJANGO_TH_H

#include <QObject>
#include <QTime>
#include <QThread>
#include <QDebug>
#include <xing.h>


class tjango_th : public QThread
{
    Q_OBJECT

public:
    tjango_th(xing *x1,Tcpserverframe *tmf);
    bool m_stopflag;
    bool playtime_flag;
    xing *x1;
    Tcpserverframe *tmf;
private:
    void run();

signals:


public slots:
};

#endif // TJANGO_TH_H
