#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    zoneCompo= new Rectangle(80,80,"Gris",600,550);

    zonec1 = new Rectangle(750,80,"Gris",175,175);
    zoner = new Rectangle(970,80,"Gris",175,175);

    zonec2 = new Rectangle(750,310,"Gris",175,175);
    zoner1 = new Rectangle(970,310,"Gris",175,175);

    zonet1 = new Rectangle(750,530,"Gris",175,175);
    zoner2 = new Rectangle(970,530,"Gris",175,175);

    v = new Vehicule();

    bc1=false;
    br=false;
    bc2=false;
    br1=false;
    bt1=false;
    br2=false;

    etatCompo=false;

    boutonCompo=true;
    boutonValider=false;
    boutonDeplacer=false;
    boutonArreter=false;
    boutonCancel=false;
    boutonCancelAll=false;

    couleurc1=ui->boxc1->currentText();
    couleurr=ui->boxr->currentText();
    couleurc2=ui->boxc2->currentText();
    couleurr1=ui->boxr1->currentText();
    couleurt1=ui->boxt1->currentText();
    couleurr2=ui->boxr2->currentText();

    grossissementc1=ui->boxTc1->currentText();
    grossissementr=ui->boxTr1->currentText();
    grossissementc2=ui->boxTc2->currentText();
    grossissementr1=ui->boxTr1->currentText();
    grossissementt1=ui->boxTt1->currentText();
    grossissementr2=ui->boxTr2->currentText();


    c1= new Cercle(815,140,couleurc1,50);
    r= new Rectangle(1005,140,couleurr,110,50);
    c2 = new Cercle(790,350,couleurc2,100);
    r1= new Rectangle(1035,345,couleurr1,50,110);
    t1= new Triangle(840,570,790,650,890,650,couleurt1);
    r2= new Rectangle(1040,600,couleurr2,40,40);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    ui->boutonVitesse->setMinimum(1);
    ui->boutonVitesse->setMaximum(8);
    ui->boutonVitesse->setTickInterval(8);




    this->repaint();

}



MainWindow::~MainWindow()
{
    delete ui;

    delete zoneCompo;
    delete zonec1;
    delete zoner;
    delete zonec2;
    delete zoner1;
    delete zonet1;
    delete zoner2;
    delete c1;
    delete r;
    delete c2;
    delete r1;
    delete t1;
    delete r2;
    delete copyc1;
    delete copyc2;
    delete copyr;
    delete copyt1;
    delete copyr2;
    delete timer;

}




void MainWindow::paintEvent(QPaintEvent* e){

    QWidget::paintEvent(e);
    QPainter painter(this);
    QList<ObjetGraphique*>::iterator it;

    zoneCompo->dessiner(&painter);
    zonec1->dessiner(&painter);
    zoner->dessiner(&painter);
    zonec2->dessiner(&painter);
    zoner1->dessiner(&painter);
    zonet1->dessiner(&painter);
    zoner2->dessiner(&painter);

   c1->setCouleur(couleurc1);
   r->setCouleur(couleurr);
   c2->setCouleur(couleurc2);
   r1->setCouleur(couleurr1);
   t1->setCouleur(couleurt1);
   r2->setCouleur(couleurr2);

   c1->dessiner(&painter);
   r->dessiner(&painter);
   c2->dessiner(&painter);
   r1->dessiner(&painter);
   t1->dessiner(&painter);
   r2->dessiner(&painter);


   for(it=v->getListe()->begin();it<v->getListe()->end();it++)
        (*it)->dessiner(&painter);

    ui->boutonDeplacerHorizontal->setEnabled(boutonDeplacer);
    ui->boutonDeplacerVertical->setEnabled(boutonDeplacer);
    ui->boutonCancel->setEnabled(boutonCancel);
    ui->boutonCancelAll->setEnabled(boutonCancelAll);
    ui->boutonArreter->setEnabled(boutonArreter);
    ui->boutonCompo->setEnabled(boutonCompo);
    ui->boutonValider->setEnabled(boutonValider);

    vitesse=ui->boutonVitesse->value();

}


void MainWindow::mousePressEvent(QMouseEvent* e) {


    if (etatCompo)
    {
        if (c1->estDansCercle(e->x(),e->y()))
        {
            bc1=true;
            br=false;
            bc2=false;
            br1=false;
            bt1=false;
            br2=false;


            if (grossissementc1=="x0.5")
                 copyc1 =  new Cercle(815,140,couleurc1,25);
            if (grossissementc1=="x1")
                 copyc1 =  new Cercle(815,140,couleurc1,50);
            if (grossissementc1=="x1.5")
                 copyc1 =  new Cercle(815,140,couleurc1,75);

            v->getListe()->push_back(copyc1);
        }

        if (r->estDansRectangle(e->x(),e->y()))
        {
            bc1=false;
            br=true;
            bc2=false;
            br1=false;
            bt1=false;
            br2=false;

            if (grossissementr=="x0.5")
                copyr = new Rectangle(1005,140,couleurr,55,25);
            if (grossissementr=="x1")
                copyr = new Rectangle(1005,140,couleurr,110,50);
            if (grossissementr=="x1.5")
                copyr = new Rectangle(1005,140,couleurr,165,75);

            v->getListe()->push_back(copyr);
        }


        if (c2->estDansCercle(e->x(),e->y()))
        {
            bc1=false;
            br=false;
            bc2=true;
            br1=false;
            bt1=false;
            br2=false;

            if (grossissementc2=="x0.5")
                 copyc2 =  new Cercle(790,350,couleurc2,50);
            if (grossissementc2=="x1")
                 copyc2 =  new Cercle(790,350,couleurc2,100);
            if (grossissementc2=="x1.5")
                 copyc2 =  new Cercle(790,350,couleurc2,150);

            v->getListe()->push_back(copyc2);
        }

        if (r1->estDansRectangle(e->x(),e->y()))
        {
            bc1=false;
            br=false;
            bc2=false;
            br1=true;
            bt1=false;
            br2=false;

            if (grossissementr1=="x0.5")
                copyr1 =new Rectangle(1035,345,couleurr1,25,55);
            if (grossissementr1=="x1")
                copyr1 =new Rectangle(1035,345,couleurr1,50,110);
            if (grossissementr1=="x1.5")
                copyr1 =new Rectangle(1035,345,couleurr1,75,165);

            v->getListe()->push_back(copyr1);

        }

        if (t1->estDansTriangle(e->x(),e->y()))
        {
            bc1=false;
            br=false;
            bc2=false;
            br1=false;
            bt1=true;
            br2=false;

            if (grossissementt1=="x0.5")
                copyt1 =new Triangle(900,550,875,590,925,590,couleurt1);
            if (grossissementt1=="x1")
                copyt1 =new Triangle(900,550,850,630,950,630,couleurt1);
            if (grossissementt1=="x1.5")
                copyt1 =new Triangle(900,550,825,670,975,670,couleurt1);

            v->getListe()->push_back(copyt1);
         }

        if (r2->estDansRectangle(e->x(),e->y()))
        {
            bc1=false;
            br=false;
            bc2=false;
            br1=false;
            bt1=false;
            br2=true;

            if (grossissementr2=="x0.5")
                copyr2 =new Rectangle(1040,600,couleurr2,20,20);
            if (grossissementr2=="x1")
                copyr2= new Rectangle(1040,600,couleurr2,40,40);
            if (grossissementr2=="x1.5")
                copyr2 =new Rectangle(1040,600,couleurr2,60,60);

            v->getListe()->push_back(copyr2);

         }


    }
}


void MainWindow::mouseMoveEvent(QMouseEvent* e) {

   if(etatCompo)
   {

        if (bc1==true)
        {
            copyc1->deplacer(e->x(),e->y());
            this->repaint();
        }

        if (br==true)
        {
           copyr->deplacer(e->x(),e->y());
           this->repaint();
        }


        if (bc2==true)
        {
            copyc2->deplacer(e->x(),e->y());
            this->repaint();
        }

        if (br1==true)
        {
            copyr1->deplacer(e->x(),e->y());
            this->repaint();
        }

        if (bt1==true)
        {
            copyt1->deplacer(e->x(),e->y());
            this->repaint();
        }

        if (br2==true)
        {
            copyr2->deplacer(e->x(),e->y());
            this->repaint();
        }
   }
}



void MainWindow::mouseReleaseEvent(QMouseEvent* e) {

    if(etatCompo)
    {
        if(br){
            if(zoneCompo->estDansRectangle(e->x()+copyr->getLargueur(),e->y()+copyr->getHauteur())&&
                    zoneCompo->estDansRectangle(e->x(),e->y()))
            {
                copyr->deplacer(e->x(),e->y());
                br=false;
            }
            else
            {

                v->getListe()->pop_back();
                br=false;
            }

        }

        if(bc1){
            if(zoneCompo->estDansRectangle(e->x()+c1->getDiam(),e->y()+c1->getDiam())&&
                    zoneCompo->estDansRectangle(e->x(),e->y()))
            {
                copyc1->deplacer(e->x(),e->y());
                bc1=false;
            }
            else
            {
                v->getListe()->pop_back();
                bc1=false;
            }


        }

        if(bc2){
            if(zoneCompo->estDansRectangle(e->x()+c2->getDiam(),e->y()+c2->getDiam())&&
                    zoneCompo->estDansRectangle(e->x(),e->y()))
            {
                copyc2->deplacer(e->x(),e->y());
                bc2=false;
            }
            else
            {
                v->getListe()->pop_back();
                bc2=false;
            }
        }

        if(br1){
            if(zoneCompo->estDansRectangle(e->x()+copyr1->getLargueur(),e->y()+copyr1->getHauteur())&&
                zoneCompo->estDansRectangle(e->x(),e->y()))
            {
                copyr1->deplacer(e->x(),e->y());
                br1=false;
            }
            else
            {

                v->getListe()->pop_back();
                br1=false;
            }

        }

       if(bt1){
            if((zoneCompo->estDansRectangle(e->x(),e->y()) &&
                zoneCompo->estDansRectangle(copyt1->getX3(),copyt1->getY3())) &&
                zoneCompo->estDansRectangle(copyt1->getX2(),copyt1->getY2()))

            {
                copyt1->deplacer(e->x(),e->y());
                bt1=false;
            }
            else
            {

                v->getListe()->pop_back();
                bt1=false;
            }

        }

       if(br2){
           if(zoneCompo->estDansRectangle(e->x()+copyr2->getLargueur(),e->y()+copyr2->getHauteur())&&
                   zoneCompo->estDansRectangle(e->x(),e->y()))
           {
               copyr2->deplacer(e->x(),e->y());
               br2=false;
           }
           else
           {

               v->getListe()->pop_back();
               br2=false;
           }

       }


      this->repaint();
    }

}



void MainWindow::on_boutonValider_clicked()
{
    QList<ObjetGraphique*>::iterator it1;

    boutonCancel=false;
    boutonCancelAll=false;
    boutonDeplacer=true;
    boutonArreter=false;

    if(!(v->getListe()->isEmpty()))
    {
        int a=v->getXCenter();
        int b=v->getYCenter();

        v->deplacerVehicule(((zoneCompo->getBordXinf()+zoneCompo->getBordXsup())/2)-a,((zoneCompo->getBordYinf()+zoneCompo->getBordYsup())/2)-b);

        etatCompo=false;

    }

    ui->boutonCompo->setStyleSheet("QPushButton { background-color: white; }");

    this->repaint();

    deplaceh=1;
    deplacev=1;

}

void MainWindow::on_boutonCompo_clicked()
{
    etatCompo=true;

    boutonValider=true;
    boutonCancel=true;
    boutonCancelAll=true;
    boutonDeplacer=false;
    boutonArreter=false;

    ui->boutonCompo->setStyleSheet("QPushButton { background-color: darkcyan; }");


}


void MainWindow::on_boutonCancel_clicked()
{
    if(!(v->getListe()->isEmpty()) && etatCompo)
        v->getListe()->pop_back();
    this->repaint();
}

void MainWindow::on_boutonCancelAll_clicked()
{
    if(etatCompo)
        v->getListe()->clear();
    this->repaint();


}



void MainWindow::on_boutonDeplacerHorizontal_clicked()
{
    boutonValider=false;
    boutonCompo=false;
    boutonCancel=false;
    boutonCancelAll=false;
    boutonArreter=true;


    direction=1;
    timer->start(5);
    this->repaint();

}


void MainWindow::on_boutonDeplacerVertical_clicked()
{

    boutonValider=false;
    boutonCompo=false;
    boutonCancel=false;
    boutonCancelAll=false;
    boutonArreter=true;


    direction=0;
    timer->start(5);
    this->repaint();

}


void MainWindow::update()
{
    if(direction==1)
    {

        if ((!(v->getBorneXMax()+vitesse>=zoneCompo->getBordXsup()))&&deplaceh)
        {
            this->v->deplacerVehicule(vitesse,0);
            this->repaint();
        }
        else
        {
            deplaceh=0;
        }

        if ((!(v->getBorneXMin()-vitesse<=zoneCompo->getBordXinf()))&&!deplaceh)
        {
            this->v->deplacerVehicule(-vitesse,0);
            this->repaint();
        }
        else
        {
            deplaceh=1;
        }


    }

    if(direction==0)
    {
        if ((!(v->getBorneYMax()+vitesse>=zoneCompo->getBordYsup()))&&deplacev)
        {
            this->v->deplacerVehicule(0,vitesse);
            this->repaint();
        }
        else
        {
            deplacev=0;
        }

        if ((!(v->getBorneYMin()-vitesse<=zoneCompo->getBordYinf()))&&!deplacev)
        {
            this->v->deplacerVehicule(0,-vitesse);
            this->repaint();
        }
        else
        {
            deplacev=1;
        }




    }
}


void MainWindow::on_boutonArreter_clicked()
{

    boutonValider=true;
    boutonCompo=true;


    timer->stop();
    this->repaint();

}






void MainWindow::on_boxc1_currentTextChanged(const QString &arg1)
{
    couleurc1=arg1;
    this->repaint();
}

void MainWindow::on_boxr_currentTextChanged(const QString &arg1)
{
    couleurr=arg1;
    this->repaint();
}

void MainWindow::on_boxc2_currentTextChanged(const QString &arg1)
{
    couleurc2=arg1;
    this->repaint();
}

void MainWindow::on_boxr1_currentTextChanged(const QString &arg1)
{
    couleurr1=arg1;
    this->repaint();
}


void MainWindow::on_boxt1_currentTextChanged(const QString &arg1)
{
    couleurt1=arg1;
    this->repaint();
}


void MainWindow::on_boxr2_currentTextChanged(const QString &arg1)
{
    couleurr2=arg1;
    this->repaint();
}


void MainWindow::on_boutonQuitter_clicked()
{
    this->close();
}



void MainWindow::on_boxTc1_currentTextChanged(const QString &arg1)
{
    grossissementc1=arg1;

    if (grossissementc1=="x0.5")
    {
         c1->deplacer(825,160);
         c1->setDiam(25);
    }
    if (grossissementc1=="x1")
    {
         c1->deplacer(815,140) ;
         c1->setDiam(50);
    }
    if (grossissementc1=="x1.5")
    {
         c1->deplacer(800,130) ;
         c1->setDiam(75);
    }

    this->repaint();
}

void MainWindow::on_boxTr_currentTextChanged(const QString &arg1)
{
    grossissementr=arg1;

    if (grossissementr=="x0.5")
    {
        r->deplacer(1035,160);
        r->setLargueur(55);
        r->setHauteur(25);
    }
    if (grossissementr=="x1")
    {
        r->deplacer(1005,140);
        r->setLargueur(110);
        r->setHauteur(50);
    }
    if (grossissementr=="x1.5")
    {
        r->deplacer(975,130);
        r->setLargueur(165);
        r->setHauteur(75);
    }

    this->repaint();
}

void MainWindow::on_boxTc2_currentTextChanged(const QString &arg1)
{
    grossissementc2=arg1;

    if (grossissementc2=="x0.5")
    {
        c2->deplacer(815,370);
        c2->setDiam(50);
    }
    if (grossissementc2=="x1")
    {
        c2->deplacer(790,350);
        c2->setDiam(100);
    }
    if (grossissementc2=="x1.5")
    {
        c2->deplacer(762,322);
        c2->setDiam(150);
    }


    this->repaint();
}

void MainWindow::on_boxTr1_currentTextChanged(const QString &arg1)
{
    grossissementr1=arg1;

    if (grossissementr1=="x0.5")
    {
        r1->deplacer(1045,370);
        r1->setLargueur(25);
        r1->setHauteur(55);
    }
    if (grossissementr1=="x1")
    {
        r1->deplacer(1035,345);
        r1->setLargueur(50);
        r1->setHauteur(110);
    }
    if (grossissementr1=="x1.5")
    {
        r1->deplacer(1020,315);
        r1->setLargueur(75);
        r1->setHauteur(165);
    }
    this->repaint();


}

void MainWindow::on_boxTt1_currentTextChanged(const QString &arg1)
{
    grossissementt1=arg1;

    if (grossissementt1=="x0.5")
    {
        t1->deplacer(840,600);
        t1->setP2(815,640);
        t1->setP3(865,640);

    }
    if (grossissementt1=="x1")
    {
        t1->deplacer(840,570);
        t1->setP2(790,650);
        t1->setP3(890,650);
    }
    if (grossissementt1=="x1.5")
    {
        t1->deplacer(840,550);
        t1->setP2(765,670);
        t1->setP3(915,670);
    }

    this->repaint();
}

void MainWindow::on_boxTr2_currentTextChanged(const QString &arg1)
{
    grossissementr2=arg1;

    if (grossissementr2=="x0.5")
    {
        r2->deplacer(1050,610);
        r2->setLargueur(20);
        r2->setHauteur(20);
    }
    if (grossissementr2=="x1")
    {
        r2->deplacer(1040,600);
        r2->setLargueur(40);
        r2->setHauteur(40);
    }
    if (grossissementr2=="x1.5")
    {
        r2->deplacer(1030,590);
        r2->setLargueur(60);
        r2->setHauteur(60);
    }
    this->repaint();
}
