#ifndef WHTTPWIGET_H
#define WHTTPWIGET_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTextDocument>
#include <QNetworkRequest>
#include <QWebPage>
#include <QWebFrame>
#include <QWebElement>
#include <QTimer>
#include <qtcsocket.h>
#include <QVector>
#include <QTextBlock>
#include <QTextDocument>
#include <QWebSettings>

#define kor(str) QString::fromLocal8Bit(str)
class WHttpwiget : public QObject
{
    Q_OBJECT
public:
    explicit WHttpwiget(QTcsocket *tcsocket,QVector<WHttpwiget *> *vecweb);
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QNetworkRequest requ;
    QByteArray replydata;
    QWebPage page;
    QWebElement document;
    bool paly_flag;
    bool vipcheck;
    QString urllastsite;
    int siteplaycount;
    int tempsitecount;
    QString findstr1;
    QString findstr2;
    QString findstr3;
    QString findstr4;
    QTimer *timer;
    QTime get_time;
    QDate get_date;
    QVector<WHttpwiget *> *vecweb;
    QNetworkRequest lasturl;
    QTcsocket *tcsocket;
    QWebSettings *setting;



signals:

public slots:
    void loadfinished(QNetworkReply* reply);
    void autostep();
    void sitemoniter();
    void read_data();
};

#endif // WHTTPWIGET_H
