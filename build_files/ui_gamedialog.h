/********************************************************************************
** Form generated from reading UI file 'gamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEDIALOG_H
#define UI_GAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameDialog
{
public:
    QStackedWidget *stackedWidget;
    QWidget *gamePausedPage;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *leftSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *topSpacer;
    QLabel *pausedLabel;
    QPushButton *returnToGameBtn;
    QPushButton *exitToMenuBtn;
    QSpacerItem *bottomSpacer;
    QSpacerItem *rightSpacer;
    QWidget *gameOverPage;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_1;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *topSpacer_1;
    QLabel *gameOverLabel;
    QLabel *yourScoreLabel;
    QLabel *highScoreLabel;
    QPushButton *playAgainBtn;
    QPushButton *exitToMenuBtn_1;
    QSpacerItem *bottomSpacer_1;
    QSpacerItem *leftSpacer_1;

    void setupUi(QDialog *GameDialog)
    {
        if (GameDialog->objectName().isEmpty())
            GameDialog->setObjectName(QString::fromUtf8("GameDialog"));
        GameDialog->resize(350, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameDialog->sizePolicy().hasHeightForWidth());
        GameDialog->setSizePolicy(sizePolicy);
        GameDialog->setMinimumSize(QSize(350, 200));
        GameDialog->setMaximumSize(QSize(350, 200));
        stackedWidget = new QStackedWidget(GameDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 350, 200));
        stackedWidget->setMinimumSize(QSize(350, 200));
        stackedWidget->setMaximumSize(QSize(350, 200));
        gamePausedPage = new QWidget();
        gamePausedPage->setObjectName(QString::fromUtf8("gamePausedPage"));
        sizePolicy.setHeightForWidth(gamePausedPage->sizePolicy().hasHeightForWidth());
        gamePausedPage->setSizePolicy(sizePolicy);
        gamePausedPage->setMinimumSize(QSize(350, 200));
        gamePausedPage->setMaximumSize(QSize(350, 200));
        horizontalLayout = new QHBoxLayout(gamePausedPage);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leftSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(leftSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        topSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(topSpacer);

        pausedLabel = new QLabel(gamePausedPage);
        pausedLabel->setObjectName(QString::fromUtf8("pausedLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pausedLabel->sizePolicy().hasHeightForWidth());
        pausedLabel->setSizePolicy(sizePolicy1);
        pausedLabel->setMinimumSize(QSize(120, 30));
        pausedLabel->setMaximumSize(QSize(120, 30));
        pausedLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(pausedLabel);

        returnToGameBtn = new QPushButton(gamePausedPage);
        returnToGameBtn->setObjectName(QString::fromUtf8("returnToGameBtn"));

        verticalLayout->addWidget(returnToGameBtn);

        exitToMenuBtn = new QPushButton(gamePausedPage);
        exitToMenuBtn->setObjectName(QString::fromUtf8("exitToMenuBtn"));

        verticalLayout->addWidget(exitToMenuBtn);

        bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(bottomSpacer);


        horizontalLayout->addLayout(verticalLayout);

        rightSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(rightSpacer);

        stackedWidget->addWidget(gamePausedPage);
        gameOverPage = new QWidget();
        gameOverPage->setObjectName(QString::fromUtf8("gameOverPage"));
        sizePolicy.setHeightForWidth(gameOverPage->sizePolicy().hasHeightForWidth());
        gameOverPage->setSizePolicy(sizePolicy);
        gameOverPage->setMinimumSize(QSize(350, 200));
        gameOverPage->setMaximumSize(QSize(350, 200));
        horizontalLayout_2 = new QHBoxLayout(gameOverPage);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_1 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        topSpacer_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(topSpacer_1);

        gameOverLabel = new QLabel(gameOverPage);
        gameOverLabel->setObjectName(QString::fromUtf8("gameOverLabel"));
        sizePolicy1.setHeightForWidth(gameOverLabel->sizePolicy().hasHeightForWidth());
        gameOverLabel->setSizePolicy(sizePolicy1);
        gameOverLabel->setMinimumSize(QSize(120, 30));
        gameOverLabel->setMaximumSize(QSize(120, 30));
        gameOverLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(gameOverLabel);

        yourScoreLabel = new QLabel(gameOverPage);
        yourScoreLabel->setObjectName(QString::fromUtf8("yourScoreLabel"));
        yourScoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(yourScoreLabel);

        highScoreLabel = new QLabel(gameOverPage);
        highScoreLabel->setObjectName(QString::fromUtf8("highScoreLabel"));
        highScoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(highScoreLabel);

        playAgainBtn = new QPushButton(gameOverPage);
        playAgainBtn->setObjectName(QString::fromUtf8("playAgainBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(playAgainBtn->sizePolicy().hasHeightForWidth());
        playAgainBtn->setSizePolicy(sizePolicy2);
        playAgainBtn->setMinimumSize(QSize(120, 0));
        playAgainBtn->setMaximumSize(QSize(120, 16777215));

        verticalLayout_5->addWidget(playAgainBtn);

        exitToMenuBtn_1 = new QPushButton(gameOverPage);
        exitToMenuBtn_1->setObjectName(QString::fromUtf8("exitToMenuBtn_1"));
        sizePolicy2.setHeightForWidth(exitToMenuBtn_1->sizePolicy().hasHeightForWidth());
        exitToMenuBtn_1->setSizePolicy(sizePolicy2);
        exitToMenuBtn_1->setMinimumSize(QSize(120, 0));
        exitToMenuBtn_1->setMaximumSize(QSize(120, 16777215));

        verticalLayout_5->addWidget(exitToMenuBtn_1);

        bottomSpacer_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(bottomSpacer_1);


        horizontalLayout_2->addLayout(verticalLayout_5);

        leftSpacer_1 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(leftSpacer_1);

        stackedWidget->addWidget(gameOverPage);

        retranslateUi(GameDialog);

        QMetaObject::connectSlotsByName(GameDialog);
    } // setupUi

    void retranslateUi(QDialog *GameDialog)
    {
        GameDialog->setWindowTitle(QApplication::translate("GameDialog", "Dialog", nullptr));
        pausedLabel->setText(QApplication::translate("GameDialog", "Game Paused", nullptr));
        returnToGameBtn->setText(QApplication::translate("GameDialog", "Return to Game", nullptr));
        exitToMenuBtn->setText(QApplication::translate("GameDialog", "Exit to Main Menu", nullptr));
        gameOverLabel->setText(QApplication::translate("GameDialog", "Game Over", nullptr));
        yourScoreLabel->setText(QApplication::translate("GameDialog", "Score: ", nullptr));
        highScoreLabel->setText(QApplication::translate("GameDialog", "High Score: ", nullptr));
        playAgainBtn->setText(QApplication::translate("GameDialog", "Play Again", nullptr));
        exitToMenuBtn_1->setText(QApplication::translate("GameDialog", "Exit to Main Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameDialog: public Ui_GameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEDIALOG_H
