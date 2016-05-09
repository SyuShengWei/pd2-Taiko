#ifndef DRUMNODE_H
#define DRUMNODE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QDebug>


class DrumRedNode :public QObject,public QGraphicsPixmapItem{
        Q_OBJECT
public:
    DrumRedNode();
public slots:
    void move();
private:
    QTimer *timerRed = new QTimer();
};


class DrumBlueNode :public QObject,public QGraphicsPixmapItem{
        Q_OBJECT
public:
    DrumBlueNode();
public slots:
    void move();
private:
    QTimer *timerBlue = new QTimer();
};


#endif // DRUMNODE_H
