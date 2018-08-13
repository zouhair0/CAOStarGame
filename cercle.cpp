#include "cercle.h"


Cercle::Cercle(int x, int y, QString c, int r):ObjetGraphique(x,y,c)
{

    this->diametre=r;
}


int Cercle::getDiam() const
{
    return diametre;
}


void Cercle::setDiam(int d)
{
    diametre=d;
}

int Cercle::getBordXsup() const
{
    return getX()+ diametre;

}

int Cercle::getBordYsup() const
{
    return getY()+ diametre;

}

int Cercle::getBordXinf() const
{
    return getX();

}

int Cercle::getBordYinf() const
{
    return getY();

}

void Cercle::dessiner(QPainter *p)
{
    if (couleur=="Vert")
      p->setBrush( QBrush( Qt::green ) );
    if( couleur=="Rouge")
      p->setBrush( QBrush( Qt::red ) );
    if (couleur=="Bleu")
      p->setBrush( QBrush( Qt::blue ) );
    if(couleur=="Jaune")
      p->setBrush( QBrush( Qt::yellow ) );
    if(couleur=="Cyan")
      p->setBrush( QBrush( Qt::cyan ) );

    p->drawEllipse(x+1,y+1,diametre-1,diametre-1);

}


bool Cercle::estDansCercle(int dx, int dy) {

    if (((dx >= x) && (dx <= x + diametre)) && ((dy >=y) && (dy <= y + diametre)))
        return true;
    else
        return false;


}
