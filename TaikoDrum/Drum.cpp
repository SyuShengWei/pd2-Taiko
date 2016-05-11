#include "Drum.h"
#include "Game.h"

extern Game *game;

Drum::Drum()
{
    //create drumnode
    timerRed = new QTimer();
    connect(timerRed,SIGNAL(timeout()),this,SLOT(createDrumRedNode()));

    timerBlue = new QTimer();
    connect(timerBlue,SIGNAL(timeout()),this,SLOT(createDrumBlueNode()));

    //create drum sound player
    redSound = new QMediaPlayer();
    redSound->setMedia(QUrl("qrc:/sound/sound/red.wav"));
    blueSound = new QMediaPlayer();
    blueSound->setMedia(QUrl("qrc:/sound/sound/blue.wav"));

    //initialize judgement
    judgement = new QGraphicsPixmapItem();
    judgement -> setPos(20,80);
    timerJudgement = new QTimer();
    connect(timerJudgement,SIGNAL(timeout()),this,SLOT(hideJudgement()));
}

void Drum::keyPressEvent(QKeyEvent *event){
    QList<QGraphicsItem *> colliding_items = collidingItems();

    if(event->key() == Qt::Key_K){
        if(redSound->state() == 1)
            redSound->setPosition(0);
        else if(redSound->state() == 0)
            redSound->play();

        int beforeSize;
        int afterSize;

        beforeSize = colliding_items.size();

        for(int i = 0 , n = colliding_items.size(); i < n ; i++){
            if(typeid(*(colliding_items[i])) == typeid(DrumRedNode)){

                if(colliding_items[i]->pos().x() - this->pos().x() <= 5 &&colliding_items[i]->pos().x() - this->pos().x() >= -5){
                    judgement->setPixmap(QPixmap(":/img/img/excellent.png"));
                    timerJudgement->start(500);
                    judgement->show();
                    game->score->increaseScore(10);//excellent => increase 10 point
                }
                else {
                    judgement->setPixmap(QPixmap(":/img/img/good.png"));
                    timerJudgement->start(500);
                    judgement->show();
                    game->score->increaseScore(5);//good => increase 5 point
                }

                //remove drumnode
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            //press wrong key ,show "bad",and decrease 1 point
            else{
                judgement->setPixmap(QPixmap(":/img/img/good.bad"));
                timerJudgement->start(500);
                judgement->show();
                game->score->increaseScore(-1);
            }
        }
            //record size again and check if delete success
            afterSize= colliding_items.size();
            if(afterSize == beforeSize){
                judgement->setPixmap(QPixmap(":/img/img/bad.png"));
                timerJudgement->start(500);
                judgement->show();
                game->score->increaseScore(-1);//not success , decrease 1 point
        }
    }
    else if(event->key() == Qt::Key_L){
        if(blueSound->state() == 1)
            blueSound->setPosition(0);
        else if(blueSound -> state() == 0)
            blueSound->play();

        int beforeSize;
        int afterSize;

        beforeSize = colliding_items.size();

        for(int i = 0 , n = colliding_items.size(); i < n ; i++){
            if(typeid(*(colliding_items[i])) == typeid(DrumBlueNode)){

                if(colliding_items[i]->pos().x() - this->pos().x() <= 5 &&colliding_items[i]->pos().x() - this->pos().x() >= -5){
                    judgement->setPixmap(QPixmap(":/img/img/excellent.png"));
                    timerJudgement->start(500);
                    judgement->show();
                    game->score->increaseScore(10);//excellent => increase 10 point
                }
                else {
                    judgement->setPixmap(QPixmap(":/img/img/good.png"));
                    timerJudgement->start(500);
                    judgement->show();
                    game->score->increaseScore(5);//good => increase 5 point
                }

                //remove drumnode
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
            //press wrong key ,show "bad",and decrease 1 point
            else{
                judgement->setPixmap(QPixmap(":/img/img/good.bad"));
                timerJudgement->start(500);
                judgement->show();
                game->score->increaseScore(-1);
            }
        }
            //record size again and check if delete success
            afterSize= colliding_items.size();
            if(afterSize == beforeSize){
                judgement->setPixmap(QPixmap(":/img/img/bad.png"));
                timerJudgement->start(500);
                judgement->show();
                game->score->increaseScore(-1);//not success , decrease 1 point
        }
    }
}

void Drum::createDrumRedNode()
{
    int ifCreate = rand()%10;
    if(ifCreate <=1 && game->gameTime > 3){
        DrumRedNode * redNode = new DrumRedNode();
        scene()->addItem(redNode);
        redNode->show();
    }
}

void Drum::createDrumBlueNode()
{
    int ifCreate = rand()%10;
    if(ifCreate <=1 && game->gameTime > 3){
        DrumBlueNode * blueNode = new DrumBlueNode();
        scene()->addItem(blueNode);
        blueNode->show();
    }
}

void Drum::hideJudgement()
{
    timerJudgement->stop();
    judgement->hide();
}
