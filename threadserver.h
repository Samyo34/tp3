#ifndef THREADSERVER_H
#define THREADSERVER_H

#include <QThread>
#include <QTcpServer>

class ThreadServer : public QThread
{

public:
    ThreadServer();
    void run();

signals :
    void changeSeason(int season);


private:
    QTcpServer* server;


};

#endif // THREADSERVER_H
