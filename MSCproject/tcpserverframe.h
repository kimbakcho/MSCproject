#ifndef TCPSERVERFRAME_H
#define TCPSERVERFRAME_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
class Tcpserverframe : public QWidget
{
    Q_OBJECT
public:
    explicit Tcpserverframe(QWidget *parent = 0);
    QLabel *QLsetip;
    QLineEdit *QEsetip;
    QLabel *QLsetport;
    QLineEdit *QEsetport;
    QPushButton *QServerstart;

    QGridLayout *mgridlayout;



signals:

public slots:
};

#endif // TCPSERVERFRAME_H
