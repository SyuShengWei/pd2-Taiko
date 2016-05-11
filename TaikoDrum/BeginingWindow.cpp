#include "BeginingWindow.h"
#include <QBrush>
#include <QImage>
#include <QCoreApplication>
#include "Game.h"

extern Game *game;

BeginingWindow::BeginingWindow()
{
    //create scene
    sceneStart = new QGraphicsScene();
    sceneStart->setSceneRect(0,0,480,320);

    //create view
    viewStart = new QGraphicsView();
    viewStart->setBackgroundBrush(QBrush(QImage(":/img/img/background.jpg")));
    viewStart->setScene(sceneStart);
    viewStart->setFixedSize(480,320);
    viewStart->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    viewStart->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //create start buttom
    Start = new QPushButton();
    Start->setGeometry(QRect(QPoint(50,80),QSize(100,85)));
    connect(Start,SIGNAL(clicked(bool)),this,SLOT(startGame()));
        //set text type
    QFont font;
    font.setPointSize(28);
    font.setWeight(QFont::Black);
    Start->setFont(font);
    Start->setText("\nStart");
        //setbackground
    QPalette palette;
    palette.setColor(QPalette::Active,QPalette::ButtonText,QColor(0,0,0));
    palette.setBrush(Start->backgroundRole(),QBrush(QPixmap(":/img/img/startButtom.png")));
    Start->setFlat(true);
    Start->setAutoFillBackground(true);
    Start->setPalette(palette);
    Start->setFixedSize(100,85);
    Start->setIconSize(QSize(100,85));
        //show it
    sceneStart->addWidget(Start);
    //create exit buttom
    Exit = new QPushButton();
    Exit->setGeometry(QRect(QPoint(350,80),QSize(80,30)));
    connect(Exit,SIGNAL(clicked()),this,SLOT(exitGame()));

    Exit->setFont(font);
    Exit->setText("\nExit");
        //setbackground
    QPalette paletteE;
    paletteE.setColor(QPalette::Active,QPalette::ButtonText,QColor(0,0,0));
    paletteE.setBrush(Exit->backgroundRole(),QBrush(QPixmap(":/img/img/exitButtom.png")));
    Exit->setFlat(true);
    Exit->setAutoFillBackground(true);
    Exit->setPalette(paletteE);
    Exit->setFixedSize(100,85);
    Exit->setIconSize(QSize(100,85));

    sceneStart->addWidget(Exit);


    viewStart->show();
}

void BeginingWindow::startGame()
{
    viewStart->hide();
    game->show();
    game->drum->timerRed->start(313);
    game->drum->timerBlue->start(277);
    game->timer->timer->start(1000);
}


void BeginingWindow::exitGame()
{
    qApp->exit();
}
