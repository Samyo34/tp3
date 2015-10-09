#include "threadclient.h"

ThreadClient::ThreadClient()
{
}

ThreadClient::ThreadClient(GameWindow *window)
{
    this->window = window;
}

void ThreadClient::s_changeS(int season)
{
    // TODO : changer la "saison"
    this->window->changeEtat(season);
}

/*ThreadClient::run(){

}*/
