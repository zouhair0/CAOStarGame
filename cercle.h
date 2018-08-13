#ifndef CERCLE_H
#define CERCLE_H

#include <QPainter>
#include "objetgraphique.h"
#include <QBrush>
#include <QMouseEvent>

class Cercle:public ObjetGraphique

{
private:

    int diametre;


public:

    Cercle(int x=0,int y=0,QString c="Bleu",int r=0);
    int getDiam() const;
    void setDiam(int d);
    int getBordXsup() const;
    int getBordYsup() const;
    int getBordXinf() const;
    int getBordYinf() const;
    
    void dessiner(QPainter *p);

    bool estDansCercle(int dx, int dy);
};


#endif // CERCLE_H
