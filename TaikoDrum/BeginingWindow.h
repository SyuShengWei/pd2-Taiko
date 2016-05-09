#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QObject>

class BeginingWindow : public QObject
{
   Q_OBJECT
public:
    BeginingWindow();
    QGraphicsScene *sceneStart;
    QGraphicsView  *viewStart;

    QPushButton * Start;
    QPushButton * Exit;

public slots:
    void startGame();
    void exitGame();

};

#endif // STARTWINDOW_H
