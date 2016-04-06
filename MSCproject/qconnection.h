#ifndef QCONNECTION_H
#define QCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QVector>
#define kor(str) QString::fromLocal8Bit(str)
class Qconnection : public QTcpSocket
{
    Q_OBJECT
public:
    explicit Qconnection(QVector<QByteArray> *protocollist);
    QByteArray readbuffer;
    QByteArray protocoldata;
    QVector<QByteArray> *protocollist;
    bool debug = false;

signals:

public slots:
    void readyforready();
};

#endif // QCONNECTION_H
