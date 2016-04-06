#ifndef WEBWIGET_H
#define WEBWIGET_H

#include <QObject>
#include <QtWebKit>
#include <QWebFrame>
#include <QUrl>
#include <QWebElement>
#include <QWebView>
#include <QDebug>
#include <QWebElementCollection>
#include <QWebElement>
#include <QTime>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

#define kor(str) QString::fromLocal8Bit(str)

class webwiget : public QWebView
{
    Q_OBJECT
public:
    explicit webwiget();
    QWebFrame *qwf;
    QWebElement document;
    QString findstr1;
    QString findstr2;
    QString findstr3;
    QString findstr4;
    QString urllastsite;
    QTime get_time;
    QDate get_date;
    int siteplaycount;
    bool vipcheck;

signals:

public slots:
    void autostep();
    void finishedpage(bool flag);
};

#endif // WEBWIGET_H
