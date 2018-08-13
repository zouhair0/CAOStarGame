#ifndef VEHICULE_H
#define VEHICULE_H

#include <QPainter>
#include "objetgraphique.h"
#include <QBrush>
#include <QMouseEvent>
#include <QList>
#include <cmath>


class Vehicule
{
protected:

    QList<ObjetGraphique*> listeVehicule;


public:
    Vehicule();
    QList<ObjetGraphique*>* getListe();
    int getBorneXMax();
    int getBorneXMin();
    int getBorneYMax();
    int getBorneYMin();
    int getXCenter();
    int getYCenter();
    bool estDansZone(int xmin,int xmax,int ymin,int ymax);
    void deplacerVehicule(int pasX, int pasY);




};

#endif // VEHICULE_H
