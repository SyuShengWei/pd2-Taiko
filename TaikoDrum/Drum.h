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

class Drum:public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Drum();
    void keyPressEvent(QKeyEvent *event);
    void setRandomDrum(int number);
    QTimer *timerRed;
    QTimer *timerBlue;
private:
    int random_drum;
    QTimer * nodeTimer;
    int score;

public slots:
    void createDrumRedNode();
    void createDrumBlueNode();
};

#endif // DRUM_H
