#include "Game.h"
#include <QBrush>
#include <QImage>


Game::Game()
{
    //create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,518,364);

    //set view. P.S. Game Class is a QGraphicsView
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
    drum->show();

    //create judgement message
    scene->addItem(drum->judgement);

    //create score
    score = new Score();
    scene->addItem(score);
    score->setPos(0,25);

    //create game timer
    gameTime=30;
    timer = new myTimer();
    scene->addItem(timer);

    //show();
}

