#include <QTimer>
#include "threadserver.h"

ThreadServer::ThreadServer()
{
}

<<<<<<< HEAD
ThreadServer::ThreadServer(GameWindow *window)
{
    this->window = window;
}

=======
>>>>>>> 4dee81498aae2e69e48b4b640e9808a078f3ca3b

void ThreadServer::run(){
    // TODO : attendre 5 minutes envoyer le signal (emit)
    QTimer* time = new QTimer();
    int s =0;
    while(true){
<<<<<<< HEAD
        emit changeSeason(s);
=======
        //emit changeSeason(s);
>>>>>>> 4dee81498aae2e69e48b4b640e9808a078f3ca3b
        s++;
        if(s>4){
            s =0;
        }
        time->start(10000);
    }
}

