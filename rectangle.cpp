#include "rectangle.h"


Rectangle::Rectangle(int x,int y, QString c, int l, int h):ObjetGraphique(x,y,c)
{

    this->largueur=l;
    this->hauteur=h;
}


int Rectangle::getLargueur() const
{
    return largueur;
}

int Rectangle::getHauteur() const
{
    return hauteur;
}

void Rectangle::setLargueur(int larg)
{
    largueur=larg;
}

void Rectangle::setHauteur(int haut)
{
    hauteur=haut;
}

int Rectangle::getBordXsup() const
{

    return getX()+largueur;

}

int Rectangle::getBordYsup() const
{

    return getY()+hauteur;

}


int Rectangle::getBordXinf() const
{

    return getX();
}

int Rectangle::getBordYinf() const
{

    return getY();

}


void Rectangle::dessiner(QPainter *p)
{
    p->drawRect(x,y,largueur,hauteur);

    if (couleur=="Vert")
        p->fillRect(x+1,y+1,largueur-1,hauteur-1,QBrush(Qt::green));
    if( couleur=="Rouge")
        p->fillRect(x+1,y+1,largueur-1,hauteur-1,QBrush(Qt::red));
    if (couleur=="Bleu")
        p->fillRect(x+1,y+1,largueur-1,hauteur-1,QBrush(Qt::blue));
    if(couleur=="Gris")
         p->fillRect(x+1,y+1,largueur-1,hauteur-1,QBrush(QColor(170,170,170)));
    if(couleur=="Jaune")
       p->fillRect(x+1,y+1,largueur-1,hauteur-1,QBrush(Qt::yellow));
    if(couleur=="Cyan")
       p->fillRect(x+1,y+1,largueur-1,hauteur-1,QBrush(Qt::cyan));

}



bool Rectangle::estDansRectangle(int px, int py) {

    if (((px >= x) && (px <= x + largueur)) && ((py >=y) && (py <= y + hauteur)))
        return true;
    else
        return false;


}
