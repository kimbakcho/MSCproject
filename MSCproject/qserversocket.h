#ifndef QSERVERSOCKET_H
#define QSERVERSOCKET_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <qconnection.h>
#include <QVector>
#include <QLabel>

class QServersocket : public QTcpServer
{
    Q_OBJECT
public:
    explicit QServersocket(int port, QVector<QByteArray> *protocollist, QVector<Qconnection *> *socketllist,QLabel *count);
    void incomingConnection(int);
    QVector<QByteArray> *protocollist;
    QVector<Qconnection *> *socketllist;
    QLabel *count;
    int join_count;

signals:

public slots:
};

#endif // QSERVERSOCKET_H
