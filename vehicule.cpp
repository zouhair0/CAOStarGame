#include "vehicule.h"

Vehicule::Vehicule()
{

}

QList<ObjetGraphique*>* Vehicule::getListe(){

    return &listeVehicule;


}

int Vehicule::getBorneXMax(){

    int maxX=0;

   QList<ObjetGraphique*>::iterator it;

   for(it=listeVehicule.begin();it<listeVehicule.end();it++)
     {
       if((*it)->getBordXsup()>=maxX)
           maxX=(*it)->getBordXsup();
     }
   return maxX;

}

int Vehicule::getBorneXMin(){

    int minX=10000;

   QList<ObjetGraphique*>::iterator it;

   for(it=listeVehicule.begin();it<listeVehicule.end();it++)
     {
       if((*it)->getBordXinf()<=minX)
           minX=(*it)->getBordXinf();
     }

   return minX;

}

int Vehicule::getBorneYMax() {

    int maxY=0;

   QList<ObjetGraphique*>::iterator it;

   for(it=listeVehicule.begin();it<listeVehicule.end();it++)
     {
       if((*it)->getBordYsup()>=maxY)
           maxY=(*it)->getBordYsup();
     }
   return maxY;

}

int Vehicule::getBorneYMin() {

    int minY=10000;

   QList<ObjetGraphique*>::iterator it;

   for(it=listeVehicule.begin();it<listeVehicule.end();it++)
     {
       if((*it)->getBordYinf()<=minY)
           minY=(*it)->getBordYinf();
     }
   return minY;

}


int Vehicule::getXCenter(){

    return floor((getBorneXMax()+getBorneXMin())/2);
}


int Vehicule::getYCenter(){

    return floor((getBorneYMax()+getBorneYMin())/2);
}

bool Vehicule::estDansZone(int xmin,int xmax,int ymin,int ymax){

    if ((((getBorneXMax()<=xmax)&&(getBorneXMin()>=xmin))&&(getBorneYMax()<=ymax))&&(getBorneYMin()>=ymin))
        return true;
    else
        return false;

}

void Vehicule::deplacerVehicule(int pasX, int pasY){

    QList<ObjetGraphique*>::iterator it;

    for(it=listeVehicule.begin();it<listeVehicule.end();it++)
    {
         (*it)->deplacer(((*it)->getX())+pasX,((*it)->getY()+pasY));

    }
}

