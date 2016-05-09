#ifndef TIMER_H
#define TIMER_H

#include <QGraphicsTextItem>
#include <QTimer>
#include <QObject>
#include <QFont>

class myTimer :public QGraphicsTextItem{
    Q_OBJECT
public:
    myTimer();
    QTimer *timer  ;

public slots:
    void decreaseTime();

private:
    int second ;


};

#endif // TIMER_H
