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

    QGridLayout *mgridlayout;
    QServersocket *serversocket = NULL;
    QVector<QByteArray> *protocollist;

signals:

public slots:
    void serverstart();
    void QEsetport_change(QString str);
};

#endif // TCPSERVERFRAME_H
