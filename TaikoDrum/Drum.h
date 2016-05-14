#ifndef DRUM_H
#define DRUM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <stdlib.h>
#include <DrumNode.h>
#include <QObject>
#include <typeinfo>
#include <QFont>
#include <QMediaPlayer>

class Drum:public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Drum();
    void keyPressEvent(QKeyEvent *event);
    void setRandomDrum();

    QTimer *timerRed;
    QTimer *timerBlue;

    QMediaPlayer * redSound;
    QMediaPlayer * blueSound;

    QGraphicsPixmapItem * judgement;
    QTimer *timerJudgement;
private:
    int random_drum;
    QTimer * nodeTimer;

public slots:
    void createDrumRedNode();
    void createDrumBlueNode();
    void hideJudgement();
};

#endif // DRUM_H
