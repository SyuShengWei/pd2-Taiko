#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>


class Score : public QGraphicsTextItem
{
public:
    Score();
    void increaseScore(int i);
    int getScore();
    void setScore(int i);
private:
    int score;
};

#endif // SCORE_H
