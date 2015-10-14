#include "gamewindow.h"

#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QScreen>

#include <QtCore/qmath.h>
#include <QMouseEvent>
#include <QKeyEvent>
#include <time.h>
#include <sys/time.h>
#include <iostream>

#include <QtCore>
#include <QtGui>
#include "threadclient.h"
#include "threadserver.h"
using namespace std;


/* Il faut mettre les thread dans gameWindow et pas l'inverse */


int main(int argc, char **argv)
{
    srand(time(NULL));
    QGuiApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);

    Camera* cam = new Camera();

    GameWindow* win60 = new GameWindow(60);
    win60->setCamera(cam);
    win60->setFormat(format);
    win60->resize(640, 480);
    win60->show();
    win60->setAnimating(true);

    GameWindow* win120 = new GameWindow(120);
    win120->setCamera(cam);
    win120->setFormat(format);
    win120->resize(640, 480);
    win120->show();
    win120->setAnimating(true);

    GameWindow* win30 = new GameWindow(30);
    win30->setCamera(cam);
    win30->setFormat(format);
    win30->resize(640, 480);
    win30->show();
    win30->setAnimating(true);

    GameWindow* win = new GameWindow(1);
    win->setCamera(cam);
    win->setFormat(format);
    win->resize(640, 480);
    win->show();
    win->setAnimating(true);

<<<<<<< HEAD
    ThreadClient* cl1 = new ThreadClient(win60);
    ThreadClient* cl2 = new ThreadClient(win120);
    ThreadClient* cl3 = new ThreadClient(win);

    ThreadServer* serv = new ThreadServer(win30);

    /* /!\ il faut envoyer les signaux par le réseaux */

    connect(serv,SIGNAL(changeSeason(int)),cl1,SLOT(s_changeS(int)));
    connect(serv,SIGNAL(changeSeason(int)),cl2,SLOT(s_changeS(int)));
    connect(serv,SIGNAL(changeSeason(int)),cl3,SLOT(s_changeS(int)));
=======

    /* /!\ il faut envoyer les signaux par le réseaux */

   /* connect(serv,SIGNAL(changeSeason(int)),cl1,SLOT(s_changeS(int)));
    connect(serv,SIGNAL(changeSeason(int)),cl2,SLOT(s_changeS(int)));
    connect(serv,SIGNAL(changeSeason(int)),cl3,SLOT(s_changeS(int)));*/
>>>>>>> 4dee81498aae2e69e48b4b640e9808a078f3ca3b


    /*GameWindow window;
    window.setFormat(format);
    window.resize(640, 480);
    window.show();

    window.setAnimating(true);*/

    return app.exec();
}



