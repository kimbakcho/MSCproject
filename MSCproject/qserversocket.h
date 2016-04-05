#ifndef QSERVERSOCKET_H
#define QSERVERSOCKET_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class QServersocket : public QTcpServer
{
    Q_OBJECT
public:
    explicit QServersocket(QObject *parent = 0);

signals:

public slots:
};

#endif // QSERVERSOCKET_H
