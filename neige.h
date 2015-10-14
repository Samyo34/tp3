#ifndef NEIGE_H
#define NEIGE_H

#include <QVector>

#include <QRgb>
#include <QtGui/QOpenGLFunctions>

#include <iostream>

class Particule{
private:

    float x,y,z,speed;
public:
    Particule(float x, float y, float z,float speed);
    float* part=new float[15];
    float getSpeed();
    void draw();
};


class Neige
{
public:
    Neige();
    Neige(int haut, int larg);
    void update();
    void draw();

private:
    int hauteur;
    int largeur;
    QVector<Particule *> flocon;

};

#endif // NEIGE_H
