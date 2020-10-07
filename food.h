/*****************************************************************
 * Filename: food.h
 *
 * Author: Patrick Cook
 * Start Date: 9-23-2020
 *
 * Description: Interface for Food class.
 *
*****************************************************************/

#ifndef FOOD_H
#define FOOD_H

#include <QImage>
#include <QGraphicsRectItem>
#include <QObject>

class Food : public QGraphicsRectItem {
public:
    explicit Food();
    void setFood(QPointF pos = QPointF(0,0));
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
private:
    QString foodImgPath;
};

#endif // FOOD_H
