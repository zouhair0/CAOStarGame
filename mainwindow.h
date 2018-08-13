#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QList>
#include <QTimer>
#include <QPushButton>
#include <QApplication>
#include "objetgraphique.h"
#include "rectangle.h"
#include "cercle.h"
#include "triangle.h"
#include "vehicule.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void Arreter();

private slots:

    void update();

    void on_boutonValider_clicked();

    void on_boutonCompo_clicked();

    void on_boutonCancel_clicked();

    void on_boutonCancelAll_clicked();

    void on_boutonDeplacerHorizontal_clicked();

    void on_boutonDeplacerVertical_clicked();

    void on_boutonArreter_clicked();


    void on_boxc1_currentTextChanged(const QString &arg1);

    void on_boxr_currentTextChanged(const QString &arg1);

    void on_boxc2_currentTextChanged(const QString &arg1);

    void on_boxr1_currentTextChanged(const QString &arg1);

    void on_boxt1_currentTextChanged(const QString &arg1);

    void on_boxr2_currentTextChanged(const QString &arg1);

    void on_boutonQuitter_clicked();


    void on_boxTc1_currentTextChanged(const QString &arg1);

    void on_boxTr_currentTextChanged(const QString &arg1);

    void on_boxTc2_currentTextChanged(const QString &arg1);

    void on_boxTr1_currentTextChanged(const QString &arg1);

    void on_boxTt1_currentTextChanged(const QString &arg1);

    void on_boxTr2_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    Rectangle *zonec1, *zoner, *zonec2, *zoner1, *zonet1, *zoner2, *zoneCompo;

    Rectangle *r,*r1,*r2, *copyr, *copyr1, *copyr2;

    Cercle *c1, *c2,*copyc1, *copyc2;

    Triangle *t1,*copyt1;

    QString couleurr, couleurr1, couleurc1, couleurc2,couleurt1, couleurr2;

    Vehicule *v;

    QTimer * timer;


    int direction;

    bool bc1,br,bc2,br1,bt1,br2;

    bool boutonCompo, boutonDeplacer, boutonValider, boutonArreter,boutonCancel, boutonCancelAll;

    bool etatCompo;

    bool deplaceh, deplacev;

    QString grossissementc1,grossissementr,grossissementc2,grossissementr1,grossissementt1,grossissementr2;

    int vitesse;

    void paintEvent(QPaintEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);
};

#endif // MAINWINDOW_H
