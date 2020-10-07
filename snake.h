/*****************************************************************
 * Filename: snake.h
 *
 * Author: Patrick Cook
 * Start Date: 9-23-2020
 *
 * Description: Interface for Snake class.
 *
*****************************************************************/

#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QList>
#include <QObject>

#include "gameconfig.h"

class Snake : public QObject, public QGraphicsItemGroup {
    Q_OBJECT
public:
    Snake(int initPartCount = 3);
    QPointF getOffset(Direction direction) const;
    Direction getDirection() const;
    void changeDirection(Direction newDirection);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QGraphicsRectItem* getSnakeHead() const;
public slots:
    void onGrowSnake();
signals:
    void growSnake();
    void snakeCollided();
private:
    Direction m_direction;
    QList<QGraphicsRectItem*> parts;
    QGraphicsRectItem* snakeHead;
    int partCount;
    //QString headImgPath;
    //QString bodyImgPath;
};

#endif // SNAKE_H
