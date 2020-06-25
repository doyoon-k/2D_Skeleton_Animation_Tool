#pragma once
#ifndef SPRITEGRAPHICSITEM_H
#define SPRITEGRAPHICSITEM_H

#include <QGraphicsItem>

struct Sprite;

class SpriteGraphicsItem : public QGraphicsItem
{
public:
    SpriteGraphicsItem(QSharedPointer<Sprite> sprite,bool isForBindPoseGenerator = true);
    void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget = nullptr)override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event)override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event)override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event)override;
    QRectF boundingRect()const override;
    QSharedPointer<Sprite> GetSprite();
private:
    QSharedPointer<Sprite> sprite;
    bool isForBindPoseGenerator;
};

#endif // SPRITEGRAPHICSITEM_H
