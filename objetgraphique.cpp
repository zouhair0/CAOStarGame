#include "objetgraphique.h"



ObjetGraphique::ObjetGraphique(int x, int y, QString c) {

    this->x= x;
    this->y= y;
    this->couleur=c;
}

QString ObjetGraphique::getCouleur(){

    return couleur;

}

void ObjetGraphique::setCouleur(QString c){

    couleur=c;

}

void ObjetGraphique::setX(int nx){

    x=nx;

}


void ObjetGraphique::setY(int ny) {

    y=ny;
}

int ObjetGraphique::getX() const {

    return x;
}


int ObjetGraphique::getY() const {

    return y;
}



void ObjetGraphique::deplacer(int nX, int nY){

    x=nX;
    y=nY;
}


