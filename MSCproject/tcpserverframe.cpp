#include "tcpserverframe.h"

Tcpserverframe::Tcpserverframe(QWidget *parent) : QWidget(parent)
{
    QLsetip = new QLabel("Set ip");
    QEsetip = new QLineEdit();
    QLsetport = new QLabel("Set port");
    QEsetport = new QLineEdit();
    QServerstart = new QPushButton("Server\n\nStart");

    mgridlayout = new QGridLayout();
    mgridlayout->addWidget(QLsetip,0,0);
    mgridlayout->addWidget(QEsetip,0,1);
    mgridlayout->addWidget(QLsetport,1,0);
    mgridlayout->addWidget(QEsetport,1,1);
    mgridlayout->addWidget(QServerstart,0,2,2,1);

    setLayout(mgridlayout);

}

