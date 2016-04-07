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
    QTextCodec *codec;
private:
    void run();

signals:

public slots:
};

#endif // QPROTOCALTHEARD_H
