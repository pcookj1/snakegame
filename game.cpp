/*****************************************************************
 * Filename: game.cpp
 *
 * Author: Patrick Cook
 * Start Date: 9-23-2020
 *
 * Description: MainWindow for the Snake Game. Currently allows
 * for a single player game. A Snake is spawned by default with a head and two
 * tail pieces. Food is randomly placed on the board. The game advances
 * by the timeout() signal of timer. The WASD keys are used to change the snake's
 * direction.
 *
 * Pressing ESC brings up a pause menu dialog. On Game over, the same dialog displays
 * a Game Over menu which displays the highscore. The snake moves in a grid-
 * like pattern. A grid piece is SNAKE_BODY_SIZE+2. The QGraphicsScene used to
 * hold the snake and food has a 2-pixel buffer with the outermost snake path to avoid
 * collisions against the wall. The snake's movement is defined within the Snake class.
 *
*****************************************************************/

#include <QFile>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QLineF>
#include <QObject>
#include <QRandomGenerator>
#include <QSound>
#include <QTextStream>
#include <QTimer>
#include <QWidget>

#include <QDebug>

#include "food.h"
#include "game.h"
#include "gameconfig.h"
#include "gamedialog.h"
#include "snake.h"
#include "ui_snakegame.h"


Game::Game(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::SnakeGame),
    snake(new Snake(3)), food(new Food()),
    scene(new QGraphicsScene(this)),
    timer(new QTimer(this)), player(new QMediaPlayer(this)),
    gameDialog(new GameDialog(this)),
    gameRunning(false), gameFinished(false),
    score(0) {

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    // Set graphicsView rect to remove margins (prevents scroll bar glitch)
    QRectF rcontent = ui->graphicsView->contentsRect();
    ui->graphicsView->setSceneRect(0, 0, rcontent.width(), rcontent.height());

    // Scene dimensions multiple of SNAKE_BODY_SIZE + 2 (770 x 638), with 2 pixels for buffer against border
    scene->setSceneRect(0, 0, 772, 640);
    scene->setBackgroundBrush(QBrush(QColor(247, 247, 188))); // beige background
    ui->graphicsView->setScene(scene);

    player->setMedia(QUrl("qrc:/sounds/sounds/apple_crunch.wav"));

    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    // Add Borders
    scene->addLine(TopLine, QPen(Qt::black));
    scene->addLine(LeftLine, QPen(Qt::black));
    scene->addLine(RightLine, QPen(Qt::black));
    scene->addLine(BottomLine, QPen(Qt::black));

    // Connect QTimer to updateGame and scene advance slots
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));

    // Connect slots to snakeAteFood signal
    connect(this, SIGNAL(snakeAteFood()), this, SLOT(newFood()));

    // Connect signal to slot for single player game
    connect(ui->singlePlayerButton, SIGNAL(clicked(bool)), this, SLOT(startGame()));

    // connect dialog signals to game
    connect(this, SIGNAL(gameOver()), gameDialog, SIGNAL(gameOver()));
    connect(this, SIGNAL(gamePaused()), gameDialog, SIGNAL(gamePaused()));
    connect(gameDialog, SIGNAL(playAgain()), this, SLOT(onPlayAgain()));
    connect(gameDialog, SIGNAL(exitToMainMenu()), this, SLOT(onExitToMainMenu()));
    connect(gameDialog, SIGNAL(resumeGame()), this, SLOT(onResumeGame()));


}

Game::~Game() {

    delete ui;
}

//void SnakeGame::singlePlayerGame() {

//    //Change Index to game page
//    game->startGame();
//}


void Game::startGame() {

    score = 0;
    snake = new Snake(3);

    // connect snake
    connect(this, SIGNAL(snakeAteFood()), snake, SIGNAL(growSnake()));
    connect(snake, SIGNAL(snakeCollided()), this, SLOT(onGameOver()));

    gameRunning = true;
    gameFinished = false;

    newFood();
    scene->addItem(food);
    scene->addItem(snake);

    ui->stackedWidget->setCurrentIndex(1);
    timer->start(GAME_TIMER);
}

void Game::updateGame() {

    if((!gameRunning) && (!gameFinished)) {
        return;
    }
    checkIfAteFood();
}

void Game::checkIfAteFood() {

    // Dirty fix to detect food collision since collidingItems doesn't detect food
    // for some reason
    if(snake->getSnakeHead()->pos() == food->pos()) {
        score++;
        player->play(); // apple crunch sound
        emit snakeAteFood();
    }
}

void Game::keyPressEvent(QKeyEvent *event) {

    switch(event->key()) {
    case Qt::Key_A:
        if(snake->getDirection() != Direction::RIGHT) {
            snake->changeDirection(Direction::LEFT);
        }
        break;
    case Qt::Key_D:
        if(snake->getDirection() != Direction::LEFT) {
            snake->changeDirection(Direction::RIGHT);
        }
        break;
    case Qt::Key_W:
        if(snake->getDirection() != Direction::DOWN) {
            snake->changeDirection(Direction::UP);
        }
        break;
    case Qt::Key_S:
        if(snake->getDirection() != Direction::UP) {
            snake->changeDirection(Direction::DOWN);
        }
        break;
    case Qt::Key_Escape:
        if(gameFinished) {
            onGameOver();
        } else {
            onGamePaused();
        }
        break;
    }
    QMainWindow::keyPressEvent(event);
}

void Game::newFood() {

    // Generate random food position within scene boundaries
    QRectF const sceneDim = scene->sceneRect();
    int xPos = QRandomGenerator::global()->bounded(sceneDim.width()) - SNAKE_BODY_SIZE;
    int yPos = QRandomGenerator::global()->bounded(sceneDim.height()) - SNAKE_BODY_SIZE;

    // Round position to align with nearest tile (tiles are SNAKE_BODY_SIZE+2 in width and height)
    xPos = (qRound(float((xPos/((SNAKE_BODY_SIZE) + 2)))) * (SNAKE_BODY_SIZE + 2)) + 2;
    yPos = (qRound(float((yPos/((SNAKE_BODY_SIZE) + 2)))) * (SNAKE_BODY_SIZE + 2)) + 2;
    QPointF randPos = QPointF(xPos, yPos);

        //std::cout << xPos << " X by Y " << yPos << std::endl;
    food->setFood(randPos);
    update();
}

void Game::onGameOver() {

    timer->stop();
    emit gameOver();
    gameFinished = true;

    // Set high score
    int hScore;
    QFile highscore("highscore.txt");
    if(highscore.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QString line = highscore.readLine();
        if(line.isEmpty() | (line.toInt() < score)) {
            highscore.resize(0); // clear highscore
            QTextStream stream(&highscore);
            stream << QString::number(score);
            highscore.close();
            hScore = score;
        } else {
            hScore = line.toInt();
        }
    }


    gameDialog->setScore(score, hScore);
    gameDialog->show();
}

void Game::onGamePaused() {

    timer->stop();
    emit gamePaused();
    gameRunning = false;
    gameDialog->show();
}

void Game::onResumeGame() {

    if(gameFinished) {
        return;
    }
    gameRunning = true;
    gameDialog->close();
    timer->start();
}

void Game::onExitToMainMenu() {

    gameDialog->close();
    scene->removeItem(snake);
    scene->removeItem(food);
    ui->stackedWidget->setCurrentIndex(0);

}

void Game::onPlayAgain() {

    gameDialog->close();
    scene->removeItem(snake);
    scene->removeItem(food);
    startGame();
}
