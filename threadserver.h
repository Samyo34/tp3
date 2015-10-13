#ifndef THREADSERVER_H
#define THREADSERVER_H

#include <QThread>
#include <QTcpServer>
#include "gamewindow.h"

class ThreadServer : public QThread
{

public:
    ThreadServer();
    ThreadServer(GameWindow* window);
    void run();

signals :
    void changeSeason(int season);


private:
    QTcpServer* server;
    GameWindow* window;


};

#endif // THREADSERVER_H
