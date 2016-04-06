#ifndef QTICHDATA_H
#define QTICHDATA_H

#include <QObject>
#include <QString>

class Qrichdata
{

public:
    explicit Qrichdata();
    QString hname;
    QString price;
    QString loss;
    QString obj;
    QString shcode;
    bool loss_flag;
    bool obj_flag;

signals:

public slots:
};

#endif // QTICHDATA_H
