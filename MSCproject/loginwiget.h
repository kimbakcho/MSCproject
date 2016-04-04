#ifndef LOGINWIGET_H
#define LOGINWIGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
#include <QSettings>
#include "xing.h"

#define kor(str) QString::fromLocal8Bit(str)

extern xing *x1;

class Loginwiget : public QWidget
{
    Q_OBJECT
public:
    explicit Loginwiget(xing *x1,QWidget *parent = 0);
signals:

public slots:

private:
    xing *x1;
    QLabel *lbid;
    QLabel *lbpw;
    QLabel *lbaupw;
    QPushButton *pbjoin;
    QLineEdit *leid;
    QLineEdit *lepw;
    QLineEdit *leaupw;
    QGridLayout *glay_1;
private slots:
    void loginfuntion();

};

#endif // LOGINWIGET_H
