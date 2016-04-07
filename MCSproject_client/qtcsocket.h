#ifndef QTCSOCKET_H
#define QTCSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>


class QTcsocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit QTcsocket(QString ip, int port);
    QTimer *connecttimer;
    QString ip;
    int port;


signals:

public slots:
    void timeout_connectcheck();
};

#endif // QTCSOCKET_H
