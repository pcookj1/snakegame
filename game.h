/*****************************************************************
 * Filename: game.h
 *
 * Author: Patrick Cook
 * Start Date: 9-23-2020
 *
 * Description: Interface for Game class.
 *
*****************************************************************/

#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QObject>
#include <QTimer>

#include "food.h"
#include "gameconfig.h"
#include "gamedialog.h"
#include "snake.h"

namespace Ui {
    class SnakeGame;
}

class Game : public QMainWindow {
    Q_OBJECT
public:
    explicit Game(QWidget *parent = 0);
    ~Game();
public slots:
    void startGame();
signals:
    void snakeAteFood();
    void gameOver();
    void gamePaused();
private slots:
    void updateGame();
    void checkIfAteFood();
    void keyPressEvent(QKeyEvent *event);
    void newFood();
    void onGameOver();
    void onGamePaused();
    void onResumeGame();
    void onExitToMainMenu();
    void onPlayAgain();
private:
    Ui::SnakeGame *ui;
    Snake *snake;
    Food *food;
    QGraphicsScene *scene;
    QTimer *timer;
    QMediaPlayer *player;
    GameDialog *gameDialog;
    bool gameRunning;
    bool gameFinished;
    int score;
};

#endif // GAME_H

