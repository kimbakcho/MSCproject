#ifndef QSERVERSOCKET_H
#define QSERVERSOCKET_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <qconnection.h>
#include <QVector>

class QServersocket : public QTcpServer
{
    Q_OBJECT
public:
    explicit QServersocket(int port,QVector<QByteArray> *protocollist);
    void incomingConnection(int);
    QVector<QByteArray> *protocollist;

signals:

public slots:
};

#endif // QSERVERSOCKET_H
