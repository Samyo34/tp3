#ifndef FENETRESERVER_H
#define FENETRESERVER_H

#include <QMainWindow>
#include "threadserver.h"

class FenetreServer : QMainWindow
{
public:
    FenetreServer();

private:
    ThreadServer*  server;

};

#endif // FENETRESERVER_H
