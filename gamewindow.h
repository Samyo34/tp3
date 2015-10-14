#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "openglwindow.h"
#include "camera.h"
#include "threadclient.h"
#include "threadserver.h"
#include "neige.h"





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

    void setColor(GLfloat red,GLfloat green, GLfloat blue);
    void setSaison(int s);
    int getSaison();


private:

    Camera *camera;
    QTimer *timer;
    int fps = 60;
    int m_frame;
    QImage m_image;
    point *p;

    ThreadClient* client;
    Neige* n;

    int carte=1;

    int saison=0; // 0:neutre, 1: ete, 2:automne, 3:hiver,4;printemps;

    GLfloat rouge,vert,bleu;
    int etat;
    float rotX = -45.0;
    float rotY = -45.0;
    float ss = 1.0f;

private slots:
    void leChangementCMaintenant();


};


#endif // GAMEWINDOW_H
