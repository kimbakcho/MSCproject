#ifndef QCONNECTION_H
#define QCONNECTION_H

#include <QObject>
#include <QTcpSocket>

class Qconnection : public QTcpSocket
{
    Q_OBJECT
public:
    explicit Qconnection(QObject *parent = 0);

signals:

public slots:
};

#endif // QCONNECTION_H
