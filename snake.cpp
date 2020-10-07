/*****************************************************************
 * Filename: snake.cpp
 *
 * Author: Patrick Cook
 * Start Date: 9-23-2020
 *
 * Description: Custom QGraphicsItemGroup class which controls snake movement
 * and painting information called by the parent scene. Uses a signal sent
 * by the game to handle growing the tail by one body part. Handles scene collisions
 * against the head with the exception of food, which is handled elsewhere by the scene.
 *
*****************************************************************/

#include <QBrush>
#include <QDebug>
#include <QList>
#include <QObject>
#include <QPointF>
#include <QGraphicsRectItem>

#include "food.h"
#include "gameconfig.h"
#include "snake.h"

Snake::Snake(int initPartCount) : partCount(initPartCount) {

    connect(this, SIGNAL(growSnake()), this, SLOT(onGrowSnake()));

    changeDirection(Direction::RIGHT);
    for(int i = 0; i != partCount; ++i) {
        QGraphicsRectItem *part = new QGraphicsRectItem(QRect(0, 0, SNAKE_BODY_SIZE, SNAKE_BODY_SIZE), this);
        parts << part;
    }
    snakeHead = parts.front();
    // Set snake to grid pieces roughly in the middle
    snakeHead->setPos((qRound(float(400/((SNAKE_BODY_SIZE) + 2))) * (SNAKE_BODY_SIZE + 2)) + 2,
                      (qRound(float(300/((SNAKE_BODY_SIZE) + 2))) * (SNAKE_BODY_SIZE + 2)) + 2);

}

QPointF Snake::getOffset(Direction direction) const {

    switch(direction) {
    case Direction::UP:
        return QPointF(0, -SNAKE_BODY_SIZE - 2);
    case Direction::DOWN:
        return QPointF(0, SNAKE_BODY_SIZE + 2);
    case Direction::LEFT:
        return QPointF(-SNAKE_BODY_SIZE - 2, 0);
    case Direction::RIGHT:
        return QPointF(SNAKE_BODY_SIZE + 2, 0);
    default:
        return QPointF(0,0);
    }
}

Direction Snake::getDirection() const {

    return m_direction;
}

void Snake::changeDirection(Direction newDirection) {

    switch(newDirection) {
    case Direction::UP:
        m_direction = Direction::UP;
        break;
    case Direction::DOWN:
        m_direction = Direction::DOWN;
        break;
    case Direction::LEFT:
        m_direction = Direction::LEFT;
        break;
    case Direction::RIGHT:
        m_direction = Direction::RIGHT;
        break;
    }
}

void Snake::advance(int phase) {

    if(!phase)
        return;

    // Advance head position, and move each body part to pos of its neighbor
    QPointF const offset = getOffset(m_direction);
    QPointF prevPartPos = parts.first()->pos();
    parts.first()->setPos(prevPartPos + offset);
        //qInfo() << "head moved to" << parts.first()->pos();
    for(int i = 1; i != partCount; ++i) {
        QGraphicsRectItem *part = parts.at(i);
        QPointF const partPos = part->pos();
        part->setPos(prevPartPos);
        prevPartPos = partPos;
    }

    // Check collisions against self and scene boundaries
    QList<QGraphicsItem*> collisions = getSnakeHead()->collidingItems();
    for(auto it = collisions.begin(); it != collisions.end(); ++it) {
            //std::cout << "a collision item" << std::endl;
        emit snakeCollided();
    }
}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    QBrush headBrush(Qt::darkGreen);
    QBrush bodyBrush(Qt::green);

    for(int i = 1; i != partCount; ++i) {
        QGraphicsRectItem *part = parts.at(i);
        part->setBrush(bodyBrush);
    }
    QGraphicsRectItem *part = parts.front();
    part->setBrush(headBrush);
}

void Snake::onGrowSnake() {

    QGraphicsRectItem *part = new QGraphicsRectItem(QRect(0, 0, SNAKE_BODY_SIZE, SNAKE_BODY_SIZE), this);
    part->setPos(parts.last()->pos()); //temporarily place in over the tail to prevent screen artifact
    partCount++;
    parts << part;
    update();
}

QGraphicsRectItem *Snake::getSnakeHead() const {

    return snakeHead;
}
