#include "Drum.h"


#include "Game.h"

extern Game *game;

Drum::Drum()
{
    //create drumnode
    timerRed = new QTimer();
    connect(timerRed,SIGNAL(timeout()),this,SLOT(createDrumRedNode()));
    //timerRed->start(300);
    timerBlue = new QTimer();
    connect(timerBlue,SIGNAL(timeout()),this,SLOT(createDrumBlueNode()));
    //timerBlue->start(233);
    //show score

}

void Drum::keyPressEvent(QKeyEvent *event){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    if(event->key() == Qt::Key_K){
        qDebug() << "press K";
        for(int i = 0 , n = colliding_items.size(); i < n ; i++){
            if(typeid(*(colliding_items[i])) == typeid(DrumRedNode)){
                //update score
                game->score->increaseScore(1);
                //remove drumnode
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
        }
    }
    else if(event->key() == Qt::Key_L){
        qDebug() << "press L";
        for(int i = 0 , n = colliding_items.size(); i < n ; i++){
            if(typeid(*(colliding_items[i])) == typeid(DrumBlueNode)){
                //update score
                game->score->increaseScore(1);
                //remove drumnode
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                return;
            }
        }
    }
}

void Drum::createDrumRedNode()
{
    int ifCreate = rand()%10;
    if(ifCreate <=1){
        DrumRedNode * redNode = new DrumRedNode();
        qDebug() <<"create red";
        scene()->addItem(redNode);
        redNode->show();
    }
}

void Drum::createDrumBlueNode()
{
    int ifCreate = rand()%10;
    if(ifCreate <=1){
        DrumBlueNode * blueNode = new DrumBlueNode();
        qDebug() <<"create blue";
        scene()->addItem(blueNode);
        blueNode->show();
    }
}
