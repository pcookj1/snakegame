/*****************************************************************
 * Filename: gamedialog.h
 *
 * Author: Patrick Cook
 * Start Date: 9-23-2020
 *
 * Description: Interface for GameDialog class.
 *
*****************************************************************/

#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>
#include <QWidget>

namespace Ui {
    class GameDialog;
}

class GameDialog : public QDialog {
    Q_OBJECT
public:
    explicit GameDialog(QWidget *parent = nullptr);
    ~GameDialog();
signals:
    void gameOver();
    void gamePaused();
    void resumeGame();
    void exitToMainMenu();
    void playAgain();
public slots:
    void onGameOver();
    void onGamePaused();
    void setScore(int score, int highScore);
private:
    Ui::GameDialog *ui;
};

#endif // GAMEDIALOG_H
