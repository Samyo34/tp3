#include "neige.h"

Neige::Neige()
{

}

Neige::Neige(int haut, int larg)
{
    this->hauteur=haut;
    this->largeur=larg;
    for(int i=0;i<30;i++){
        flocon.push_back(new Particule(qrand()%larg,5.0f,qrand()%haut,0.5f));
    }
}

void Neige::update()
{
    for(int i=0;i<flocon.size();i++){
        for(int j=1;j<14;j+=3){
            flocon.at(i)->part[j]+=flocon.at(i)->getSpeed();
        }
    }
}

void Neige::draw()
{
    for(int i=0;i<flocon.size();i++){
        flocon.at(i)->draw();
    }

    std::cout<<"je suis ici"<<std::endl;
}


Particule::Particule(float x, float y, float z, float speed)
{
    this->x=x;
    this->y=y;
    this->z=z;
    this->speed=speed;
    part[0]=x;
    part[1]=y;
    part[2]=z;

    part[3]=x-0.1f;
    part[4]=y;
    part[5]=z;

    part[6]=x;
    part[7]=y+0.1f;
    part[8]=z;

    part[9]=x+0.1f;
    part[10]=y;
    part[11]=z;

    part[12]=x;
    part[13]=y-0.1f;
    part[14]=z;
}

float Particule::getSpeed()
{
    return speed;
}

void Particule::draw()
{
    glPointSize(3);
    glColor3f(0.9, 0.8, 0.9);
    glBegin(GL_POINTS);

    for(int i=0;i<15;i+=3){
        glVertex3f(part[i],part[i+1],part[i+2]);
    }
    glEnd();
}
