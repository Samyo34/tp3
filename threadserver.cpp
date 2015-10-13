#include <QTimer>
#include "threadserver.h"

ThreadServer::ThreadServer()
{
}

ThreadServer::ThreadServer(GameWindow *window)
{
    this->window = window;
}


void ThreadServer::run(){
    // TODO : attendre 5 minutes envoyer le signal (emit)
    QTimer* time = new QTimer();
    int s =0;
    while(true){
        emit changeSeason(s);
        s++;
        if(s>4){
            s =0;
        }
        time->start(10000);
    }
}

