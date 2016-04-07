#ifndef TCPSERVERFRAME_H
#define TCPSERVERFRAME_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <qserversocket.h>
#include <QSettings>
#include <QVector>
#include <qconnection.h>
class Tcpserverframe : public QWidget
{
    Q_OBJECT
public:
    explicit Tcpserverframe(QVector<QByteArray> *protocollist, QWidget *parent = 0);
    QLabel *QLsetip;
    QLineEdit *QEsetip;
    QLabel *QLsetport;
    QLineEdit *QEsetport;
    QPushButton *QServerstart;
    QLabel *joincount;
    QLabel *joincount_data;
    QLabel *QLaccnumber;
    QLineEdit *QEjaccnumber;

    QLabel *QLpwumber;
    QLineEdit *QEjpwumber;

    QLabel *QLmoneyprice;
    QLineEdit *QEjQLmoneyprice;


    QPushButton *Qremotestart;
    QPushButton *Qremotestop;

    QGridLayout *mgridlayout;
    QServersocket *serversocket;
    QVector<QByteArray> *protocollist;
    QVector<Qconnection *> *socketllist;

signals:

public slots:
    void serverstart();
    void remotestart();
    void remotestop();
    void QEsetport_change(QString str);
    void QEjaccnumber_change(QString str);
    void QEjpwumber_change(QString str);
    void QEjQLmoneyprice_change(QString str);
};

#endif // TCPSERVERFRAME_H
