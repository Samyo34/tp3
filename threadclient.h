#ifndef THREADCLIENT_H
#define THREADCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QHostAddress>

class ThreadClient : public QObject
{
Q_OBJECT
public:
    ThreadClient();
    public slots:
    void readData();

private:
    QTcpSocket* socket;

};

#endif // THREADCLIENT_H
