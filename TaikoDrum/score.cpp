#include "Score.h"
#include <QFont>


Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText("Score:" + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::increaseScore(int i)
{
    score = score + i;
    setPlainText("Score:" + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

int Score::getScore()
{
    return score ;
}

void Score::setScore(int i)
{
    score = i ;
}
