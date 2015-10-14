#ifndef THREADSERVER_H
#define THREADSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QVector>
#include <QString>
#include <algorithm>


class ThreadServer : QObject
{
Q_OBJECT
public:
    ThreadServer();
    void run();

signals :
    //void changeSeason(int season);

public slots:
    void emitSeason();

private slots :
    void newClient();



private:
    QTcpServer* server;

    QTimer* time;

    QVector<QTcpSocket* > clients;


};

#endif // THREADSERVER_H
