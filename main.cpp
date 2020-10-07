/*****************************************************************
 * Filename: main.cpp
 *
 * Author: Patrick Cook
 * Start Date: 9-23-2020
 *
 * Description: QApplication which instantiates and displays the game
 * window.
 *
*****************************************************************/

#include <QApplication>

#include "game.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    Game w;
    w.show();

    return a.exec();
}
