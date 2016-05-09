#include "DrumNode.h"
#include <stdlib.h>
#include "Game.h"

extern Game *game;

DrumRedNode::DrumRedNode(){
    int whichDrum = rand()%2;
    if (whichDrum == 0)
        setPixmap(QPixmap(":/img/img/redBig.png"));
    else
        setPixmap(QPixmap(":/img/img/redSmall.png"));

    setPos(520,120);
    connect(timerRed,SIGNAL(timeout()),this,SLOT(move()));
    timerRed->start(12);
}

void DrumRedNode::move(){
    setPos(x()-3,y());
    if(pos().x() + pixmap().width() < -520 ||game->gameTime == 0){
        scene()->removeItem(this);
        delete this ;
        qDebug() << "delete";
    }
}

DrumBlueNode::DrumBlueNode(){
    int whichDrum = rand()%2;
    if (whichDrum == 0)
        setPixmap(QPixmap(":/img/img/blueSmall.png"));
    else
        setPixmap(QPixmap(":/img/img/bluebig.png"));

    setPos(520,120);
    connect(timerBlue,SIGNAL(timeout()),this,SLOT(move()));
    timerBlue->start(12);
}

void DrumBlueNode::move(){
    setPos(x()-3,y());
    if(pos().x() + pixmap().width() < -520 ||game->gameTime == 0){
        scene()->removeItem(this);
        delete this ;
        qDebug() << "delete";
    }

}
