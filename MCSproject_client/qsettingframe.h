#ifndef QSETTINGFRAME_H
#define QSETTINGFRAME_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QSettings>
#include <qtcsocket.h>
#include <webwiget.h>

class QSettingframe : public QWidget
{
    Q_OBJECT
public:
    explicit QSettingframe(QTcsocket *tcsocket,QVector<webwiget *> *vecweb,QWidget *parent = 0);
    QLabel *QLSetip;
    QLineEdit *QEsetip;
    QLabel *QLSetport;
    QLineEdit *QEsetport;
    QGridLayout *gridlayout;
    QPushButton *Qstartbutton;
    QTcsocket *tcsocket;
    QLabel *QLwebwigetcount;
    QLineEdit *QEwebwigetcount;
    QVector<webwiget *> *vecweb;



signals:

public slots:
    void QEsetip_change(QString str);
    void QEsetport_change(QString str);
    void QEwebwigetcount_change(QString str);
    void Qstartbutton_push();
};

#endif // QSETTINGFRAME_H
