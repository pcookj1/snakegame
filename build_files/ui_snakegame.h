/********************************************************************************
** Form generated from reading UI file 'snakegame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKEGAME_H
#define UI_SNAKEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SnakeGame
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *titlePage;
    QPushButton *singlePlayerButton;
    QWidget *singleGamePage;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SnakeGame)
    {
        if (SnakeGame->objectName().isEmpty())
            SnakeGame->setObjectName(QString::fromUtf8("SnakeGame"));
        SnakeGame->resize(800, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SnakeGame->sizePolicy().hasHeightForWidth());
        SnakeGame->setSizePolicy(sizePolicy);
        SnakeGame->setMinimumSize(QSize(800, 700));
        SnakeGame->setMaximumSize(QSize(800, 700));
        centralWidget = new QWidget(SnakeGame);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 780, 650));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(780, 650));
        stackedWidget->setMaximumSize(QSize(780, 650));
        titlePage = new QWidget();
        titlePage->setObjectName(QString::fromUtf8("titlePage"));
        singlePlayerButton = new QPushButton(titlePage);
        singlePlayerButton->setObjectName(QString::fromUtf8("singlePlayerButton"));
        singlePlayerButton->setGeometry(QRect(290, 295, 200, 30));
        singlePlayerButton->setMinimumSize(QSize(200, 30));
        singlePlayerButton->setMaximumSize(QSize(200, 30));
        stackedWidget->addWidget(titlePage);
        singleGamePage = new QWidget();
        singleGamePage->setObjectName(QString::fromUtf8("singleGamePage"));
        graphicsView = new QGraphicsView(singleGamePage);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(4, 5, 772, 640));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(772, 640));
        graphicsView->setMaximumSize(QSize(772, 640));
        graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
        stackedWidget->addWidget(singleGamePage);
        SnakeGame->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SnakeGame);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 17));
        SnakeGame->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SnakeGame);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SnakeGame->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SnakeGame);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SnakeGame->setStatusBar(statusBar);

        retranslateUi(SnakeGame);

        QMetaObject::connectSlotsByName(SnakeGame);
    } // setupUi

    void retranslateUi(QMainWindow *SnakeGame)
    {
        SnakeGame->setWindowTitle(QApplication::translate("SnakeGame", "Snake", nullptr));
        singlePlayerButton->setText(QApplication::translate("SnakeGame", "Single Player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SnakeGame: public Ui_SnakeGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKEGAME_H
