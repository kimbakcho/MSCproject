#ifndef TPRICEMONITER_H
#define TPRICEMONITER_H

#include <QObject>
#include <QThread>
#include <QList>
#include <QDebug>
#include <QString>
#include <qrichdata.h>
#include <xing.h>
class tpricemoniter : public QThread
{
    Q_OBJECT
public:
    explicit tpricemoniter(xing *x1,QMap<QString,Qrichdata *> *richdata);
    bool m_stopflag;
    QList<QString> mapkeylist;
    QMap<QString,Qrichdata *> *richdata;
    xing *x1;



private:
    void run();



signals:

public slots:
};

#endif // TPRICEMONITER_H
