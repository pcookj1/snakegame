/*****************************************************************
 * Filename: gamedialog.cpp
 *
 * Author: Patrick Cook
 * Start Date: 9-23-2020
 *
 * Description: Dialog for displaying Pause and Game Over Menu.
 * Pause Menu displays buttons for exiting to main menu and resuming
 * the game.
 * Game Over Menu displays buttons for exiting to main menu and replaying
 * another game. It also displays the previous high score stored in highscore.txt
 *
*****************************************************************/

#include "gamedialog.h"
#include "ui_gamedialog.h"

#include <QDialog>
#include <QString>
#include <QWidget>

GameDialog::GameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameDialog)
{

    ui->setupUi(this);
    setModal(true);

    // connect signals from game paused page
    connect(ui->returnToGameBtn, SIGNAL(clicked(bool)), this, SIGNAL(resumeGame()));
    connect(ui->exitToMenuBtn, SIGNAL(clicked(bool)), this, SIGNAL(exitToMainMenu()));

    // connect signals from game over page
    connect(ui->playAgainBtn, SIGNAL(clicked(bool)), this, SIGNAL(playAgain()));
    connect(ui->exitToMenuBtn_1, SIGNAL(clicked(bool)), this, SIGNAL(exitToMainMenu()));

    // connect game over/paused signals to display correct page
    connect(this, SIGNAL(gameOver()), this, SLOT(onGameOver()));
    connect(this, SIGNAL(gamePaused()), this, SLOT(onGamePaused()));
}

GameDialog::~GameDialog() {

    delete ui;
}

void GameDialog::onGameOver() {

    ui->stackedWidget->setCurrentIndex(1);
}

void GameDialog::onGamePaused() {

    ui->stackedWidget->setCurrentIndex(0);
}

void GameDialog::setScore(int score, int highScore) {

    QString scoreMsg("Score: ");
    QString highScoreMsg("High Score: ");
    scoreMsg.append(QString::number(score));
    highScoreMsg.append(QString::number(highScore));
    ui->yourScoreLabel->setText(scoreMsg);
    ui->highScoreLabel->setText(highScoreMsg);
}
