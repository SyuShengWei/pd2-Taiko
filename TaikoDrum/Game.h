#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "Drum.h"
#include "DrumNode.h"
#include "score.h"
#include "Timer.h"
#include <QDebug>

class Game :public QGraphicsView
{
public:
    Game();

    QGraphicsScene *scene;
    Drum *drum;
    Score *score;
    myTimer * timer;
    int gameTime ;
};

#endif // GAME_H
