#include "BeginingWindow.h"
#include <QBrush>
#include <QImage>
#include <QCoreApplication>
#include "Game.h"

extern Game *game;

BeginingWindow::BeginingWindow()
{
    //create scene
    sceneStart = new QGraphicsScene();
    sceneStart->setSceneRect(0,0,480,320);

    //create view
    viewStart = new QGraphicsView();
    viewStart->setBackgroundBrush(QBrush(QImage(":/img/img/background.jpg")));
    viewStart->setScene(sceneStart);
    viewStart->setFixedSize(480,320);
    viewStart->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    viewStart->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //create start buttom
    Start = new QPushButton();
    Start->setGeometry(QRect(QPoint(50,80),QSize(80,30)));
    Start->setText("Start");
    sceneStart->addWidget(Start);
    connect(Start,SIGNAL(clicked(bool)),this,SLOT(startGame()));
    //create exit buttom
    Exit = new QPushButton();
    Exit->setGeometry(QRect(QPoint(50,240),QSize(80,30)));
    Exit->setText("Exit");
    sceneStart->addWidget(Exit);
    connect(Exit,SIGNAL(clicked()),this,SLOT(exitGame()));

    viewStart->show();
}

void BeginingWindow::startGame()
{
    viewStart->hide();
    game->show();
    game->drum->timerRed->start(300);
    game->drum->timerBlue->start(233);
    game->timer->timer->start(1000);
}


void BeginingWindow::exitGame()
{
    qApp->exit();
}
