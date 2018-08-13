#ifndef _OBJETGRAPHIQUE_H_
#define _OBJETGRAPHIQUE_H_

#include <QString>
#include <QPainter>



class ObjetGraphique
{
	
protected:
	
	int x;
	int y;
    QString couleur;

	
public:
    ObjetGraphique(int x =0, int y=0, QString c="");
    QString getCouleur();
    void setCouleur(QString c);
	void setX(int nx);
    void setY(int ny);
    int getX() const;
    int getY() const;
    virtual int getBordXsup() const=0;
    virtual int getBordYsup() const=0;
    virtual int getBordXinf() const=0;
    virtual int getBordYinf() const=0;
    virtual void deplacer(int nX, int nY);
    virtual void dessiner(QPainter *p)=0;


	

};

#endif

