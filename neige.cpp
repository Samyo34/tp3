#include "neige.h"

Neige::Neige()
{

}

Neige::Neige(int haut, int larg)
{
    this->hauteur=haut;
    this->largeur=larg;
    generateFlocon();
}

void Neige::update()
{
    for(int i=0;i<flocon.size();i++){
        for(int j=3;j<16;j+=3){
            //if(flocon.at(i)->part[j]>0.5){
                flocon.at(i)->part[j]-=flocon.at(i)->getSpeed();
            //}
        }
    }
    //generateFlocon();
}

void Neige::draw()
{
    for(int i=0;i<flocon.size();i++){
        flocon.at(i)->draw();
    }

    // std::cout<<"je suis ici"<<std::endl;
}

void Neige::generateFlocon()
{
    float valX;
    float valZ;
    float speed;
    for(int i=0;i<30;i++){
        valX = (float) (qrand()%20 / 10.0f)-0.5f;
        valZ = (float) (qrand()%20 / 10.0f)-0.5f;
        speed = (float) (qrand()%4 / 1000.0f);
        if(speed ==0){
            speed = 0.01f;
        }
        if(valX>1.0f){
            valX = 1.0f;
        }

        if(valZ>1.0f){
            valZ = 1.0f;
        }
        std::cout<<valX<<" "<<valZ<<std::endl;
        flocon.push_back(new Particule(valX ,valZ, 1.0f,speed));
    }
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

    part[3]=x-0.001f;
    part[4]=y;
    part[5]=z;

    part[6]=x;
    part[7]=y+0.001f;
    part[8]=z;

    part[9]=x+0.001f;
    part[10]=y;
    part[11]=z;

    part[12]=x;
    part[13]=y-0.001f;
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

float Particule::getX()
{
    return this->x;
}
