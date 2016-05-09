#include "Game.h"
#include <QBrush>
#include <QImage>


Game::Game()
{
    //create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,518,364);

    setBackgroundBrush(QBrush(QImage(":/img/img/bg_miss_clear.png")));

    setScene(scene);
    setFixedSize(518,364);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //create drum
    drum = new Drum();
    scene->addItem(drum);
    drum->setFlag(QGraphicsItem::ItemIsFocusable);
    drum->setFocus();
    drum->setPixmap(QPixmap(":/img/img/drumPoint.png"));
    drum->setPos(0,120);
    qDebug()<<drum->pos();
    drum->show();

    //create score
    score = new Score();
    scene->addItem(score);
    score->setPos(timer->x(),timer->y()+25);
    //create timer
    gameTime=30;
    timer = new myTimer();
    scene->addItem(timer);
    //show();
}

