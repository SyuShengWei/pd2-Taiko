#include <QApplication>
#include "Game.h"
#include "BeginingWindow.h"
#include <QDebug>

Game * game;
BeginingWindow *start;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();

    start = new BeginingWindow();

    //game->show();

    return a.exec();
}
