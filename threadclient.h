#ifndef THREADCLIENT_H
#define THREADCLIENT_H

#include <QThread>
#include <QTcpSocket>
#include "gamewindow.h"

class ThreadClient : public QThread
{

public:
    ThreadClient();
    ThreadClient(GameWindow* window);

    public slots:
    void s_changeS(int season);

private:
    QTcpSocket* socket;
    GameWindow* window;

};

#endif // THREADCLIENT_H
