/*****************************************************************
 * Filename: food.cpp
 *
 * Author: Patrick Cook
 * Start Date: 9-23-2020
 *
 * Description: Custom QGraphicsItem class for the food item. Is drawn
 * using a picture of an apple which is sized to the SNAKE_BODY_SIZE of the
 * time of writing which is 20.
 *
 * Apple image by:
 * https://iconscout.com/icons/apple
 * https://iconscout.com/contributors/aomam
 *
*****************************************************************/

#include <QBrush>
#include <QImage>
#include <QPainter>
#include <QRect>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include "food.h"
#include "gameconfig.h"

Food::Food() : foodImgPath(":/imgs/imgs/apple-lanczos3.png") {

}

void Food::setFood(QPointF pos) {

    setPos(pos);
}

void Food::advance(int phase) {

}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    QRectF rec = boundingRect();

    QBrush foodBrush;
    foodBrush.setTextureImage(QImage(foodImgPath));
    painter->fillRect(rec, foodBrush);
    painter->setPen(Qt::NoPen);
    painter->drawRect(rec);
}

QRectF Food::boundingRect() const {

    return QRect(0, 0, FOOD_SIZE, FOOD_SIZE);
}
