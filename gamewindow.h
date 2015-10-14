#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "openglwindow.h"
#include "camera.h"
#include "threadclient.h"
#include "threadserver.h"





class GameWindow : public OpenGLWindow
{
public:
    GameWindow();
    GameWindow(int fps);

    void initialize();
    void render();
    bool event(QEvent *event);

    void keyPressEvent(QKeyEvent *event);

    void displayTriangles();
    void displayLines();
    void displayTrianglesC();
    void displayPoints();
    void displayTrianglesTexture();

    void displayColor(float);

    void changeEtat(int etat);

    void loadMap(QString localPath);

    void setCamera(Camera* cam);

private:

    Camera *camera;
    QTimer *timer;
    int fps = 60;
    int m_frame;
    QImage m_image;
    point *p;

    ThreadClient* client;


    int carte=1;

    int etat = 0;
    float rotX = -45.0;
    float rotY = -45.0;
    float ss = 1.0f;

};


#endif // GAMEWINDOW_H
