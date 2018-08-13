#include "triangle.h"


Triangle::Triangle(int x1,int y1,int x2,int y2,int x3,int y3, QString couleur):ObjetGraphique(x1,y1,couleur)
{
    this->x2 =x2;
    this->y2 =y2;
    this->x3 =x3;
    this->y3 =y3;
}

void Triangle::setP2(int a, int b)
{
    x2=a;
    y2=b;
}
void Triangle::setP3(int a, int b)
{
    x3=a;
    y3=b;
}
int Triangle::getX2() const
{
    return x2;
}

int Triangle::getY2() const
{
    return y2;
}

int Triangle::getX3() const
{
    return x3;
}

int Triangle::getY3() const
{
    return y3;
}

int Triangle::getBordXsup() const
{
    return x3;
}

int Triangle::getBordYsup() const
{
    return y3;
}

int Triangle::getBordXinf() const
{
    return x2;
}

int Triangle::getBordYinf() const
{
    return y;
}

void Triangle::deplacer(int dx,int dy)
{
    int tempx,tempy,tempx2, tempy2, tempx3, tempy3;
    tempx=x; tempy=y;
    tempx2=x2; tempy2=y2;
    tempx3=x3; tempy3=y3;

    x=dx;
    y=dy;
    x2=tempx2-(tempx-dx);
    y2=tempy2-(tempy-dy);
    x3=tempx3-(tempx-dx);
    y3=tempy3-(tempy-dy);

}

bool Triangle::estDansTriangle(int dx, int dy)
{
   if((((dx>=x2) && (dx<=x3))&& (dy>=y)) && (dy<y2))
       return true;
   else
       return false;
}

void Triangle::dessiner(QPainter *p)
{

    QPainterPath path;

    path.moveTo (x,y);
    path.lineTo (x2,y2);
    path.lineTo (x3,y3);
    path.lineTo(x,y);

    if (couleur=="Vert")
      p->fillPath (path, QBrush (Qt::green));
    if( couleur=="Rouge")
       p->fillPath (path, QBrush (Qt::red));
    if (couleur=="Bleu")
       p->fillPath (path, QBrush (Qt::blue));
    if(couleur=="Jaune")
      p->fillPath (path, QBrush (Qt::yellow));
    if(couleur=="Cyan")
       p->fillPath (path, QBrush (Qt::cyan));

}

