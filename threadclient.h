#ifndef THREADCLIENT_H
#define THREADCLIENT_H

#include <QThread>
#include <QTcpSocket>

class ThreadClient : public QThread
{

public:
    ThreadClient();
    public slots:
    void s_changeS(int season);

private:
    QTcpSocket* socket;

};

#endif // THREADCLIENT_H
