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

#define kor(str) QString::fromLocal8Bit(str)

class qprotocaltheard : public QThread
{
    Q_OBJECT
public:
    explicit qprotocaltheard(QVector<QByteArray> *protocollist,QMap<QString,Qrichdata> *richdata);
    QVector<QByteArray> *protocollist;
    QMap<QString,Qrichdata> *richdata;
    QTime time;
    bool runflag;
private:
    void run();

signals:

public slots:
};

#endif // QPROTOCALTHEARD_H
