#ifndef TCPSERVERFRAME_H
#define TCPSERVERFRAME_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <qserversocket.h>
#include <QSettings>
#include <QQueue>
#include <qconnection.h>
#include <QTextEdit>
#include <QScrollBar>
#include <QListView>
#include <QStringListModel>
class Tcpserverframe : public QWidget
{
    Q_OBJECT
public:
    explicit Tcpserverframe(QQueue<QByteArray> *protocollist, QMutex *mutex, QWidget *parent = 0);
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
    QQueue<QByteArray> *protocollist;
    QVector<Qconnection *> *socketllist;
    QMutex *mutex;


    QTextEdit *logtxt;
    QScrollBar *logtxtbar;
    QListView *iplistview;
    QStringList ipliststr;
    QAbstractItemModel *iplistmodel;




signals:
    void sig_sendtxtlog(QString log);

public slots:
    void serverstart();
    void remotestart();
    void remotestop();
    void QEsetport_change(QString str);
    void QEjaccnumber_change(QString str);
    void QEjpwumber_change(QString str);
    void QEjQLmoneyprice_change(QString str);
    void slot_sendtxtlog(QString log);
};

#endif // TCPSERVERFRAME_H
