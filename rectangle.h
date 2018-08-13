#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QPainter>
#include "objetgraphique.h"
#include <QMouseEvent>

class Rectangle:public ObjetGraphique

{
private:

    int largueur;
    int hauteur;


public:

    Rectangle(int x=0,int y=0,QString c="Rouge",int l=0, int h=0);
    int getLargueur() const;
    int getHauteur() const;
    void setLargueur(int larg);
    void setHauteur(int haut);
    int getBordXsup() const;
    int getBordYsup() const;
    int getBordXinf() const;
    int getBordYinf() const;
    void dessiner(QPainter *p);
    bool estDansRectangle(int px, int py);



};



#endif // RECTANGLE_H
