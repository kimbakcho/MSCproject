#ifndef SERVERTHEARD_H
#define SERVERTHEARD_H

#include <QObject>
#include <QThread>

class Servertheard : public QThread
{
    Q_OBJECT
public:
    explicit Servertheard(QObject *parent = 0);

signals:

public slots:
};

#endif // SERVERTHEARD_H
