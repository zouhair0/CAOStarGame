#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <QGraphicsScene>
#include "objetgraphique.h"
#include <QPainter>
#include <QKeyEvent>
#include <QPoint>

class Triangle:public ObjetGraphique

{
protected:

    int x2;
    int y2;
    int x3;
    int y3;

public:

    Triangle(int x1,int y1,int x2,int y2,int x3,int y3,QString couleur="Rouge");
    void setP2(int a,int b);
    void setP3(int a,int b);
    int getX2() const;
    int getY2() const;
    int getX3() const;
    int getY3() const;
    int getBordXsup() const;
    int getBordYsup() const;
    int getBordXinf() const;
    int getBordYinf() const;
    void deplacer(int dx,int dy);
    void dessiner(QPainter *p);
    bool estDansTriangle(int dx, int dy);

};



#endif // TRIANGLE_H
