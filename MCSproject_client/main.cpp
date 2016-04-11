#include "widget.h"
#include <QApplication>
#include <qsettingframe.h>
#include <qtcsocket.h>
#include <QVector>
#include <webwiget.h>
#include <whttpwiget.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    QTcsocket *tcsocket = NULL;
    QVector<WHttpwiget *> *vecweb = new QVector<WHttpwiget *>;
    QSettingframe setframe(tcsocket,vecweb);

    setframe.show();
    setframe.Qstartbutton_push();



    return a.exec();
}
