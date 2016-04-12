#ifndef QCONNECTION_H
#define QCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QQueue>
#define kor(str) QString::fromLocal8Bit(str)
class Qconnection : public QTcpSocket
{
    Q_OBJECT
public:
    explicit Qconnection(QQueue<QByteArray> *protocollist,QMutex *mutex);
    QByteArray readbuffer;
    QByteArray protocoldata;
    QQueue<QByteArray> *protocollist;
    bool debug;
    QMutex *mutex;

signals:

public slots:
    void readyforready();
};

#endif // QCONNECTION_H
