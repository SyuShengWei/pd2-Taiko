#include "Timer.h"
#include "Game.h"
#include "Game.h"
#include <QMessageBox>
#include <QCoreApplication>

extern Game *game;

myTimer::myTimer()
{
    //initialize second
    second = 30;
    //show the time
    setPlainText("Time:" + QString::number(second));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    //start time
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(decreaseTime()));
    //timer->start(1000);

}

void myTimer::decreaseTime()
{
    //decrease Time second by second
    second --;
    setPlainText("Time:" + QString::number(second));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    game->gameTime --;
    //stop game if timer = 0;
    if(game->gameTime == 0){
        //stop game
        timer->stop();
        game->drum->timerBlue->stop();
        game->drum->timerRed->stop();
        //Give player a message
        QMessageBox::StandardButton rb = QMessageBox::question(NULL, "Show Qt","YourScore = "
                    +QString::number(game->score->getScore())+QString("\n Do You Want to Restart?"),
                    QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(rb == QMessageBox::Yes)
        {
            //initialize time
            second = 30;
            game->gameTime=30;
            setPlainText("Time:" + QString::number(second));
            setDefaultTextColor(Qt::red);
            setFont(QFont("times",16));
            //initialize score
            game->score->setScore(0);
            game->score->setPlainText("Score:" + QString::number(game->score->getScore()));
            game->score->setDefaultTextColor(Qt::red);
            game->score->setFont(QFont("times",16));
            //start all timer
            timer->start(1000);
            game->drum->timerRed->start(313);
            game->drum->timerBlue->start(277);
        }
        else if(rb ==QMessageBox::No){
            qApp->exit();
        }
    }
}
