#include "widget.h"
#include <QApplication>
#include <qsettingframe.h>
#include <qtcsocket.h>
#include <QVector>
#include <webwiget.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    QTcsocket *tcsocket = NULL;
    QVector<webwiget *> *vecweb = new QVector<webwiget *>;
    QSettingframe setframe(tcsocket,vecweb);

    setframe.show();



    return a.exec();
}
