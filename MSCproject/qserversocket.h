#ifndef QSERVERSOCKET_H
#define QSERVERSOCKET_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <qconnection.h>
#include <QQueue>
#include <QLabel>

class QServersocket : public QTcpServer
{
    Q_OBJECT
public:
    explicit QServersocket(int port, QQueue<QByteArray> *protocollist, QVector<Qconnection *> *socketllist, QLabel *count, QMutex *mutex);
    void incomingConnection(int);
    QQueue<QByteArray> *protocollist;
    QVector<Qconnection *> *socketllist;
    QLabel *count;
    int join_count;
    QMutex *mutex;

signals:

public slots:
};

#endif // QSERVERSOCKET_H
