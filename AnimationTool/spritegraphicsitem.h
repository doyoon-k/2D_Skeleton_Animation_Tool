#ifndef SPRITEGRAPHICSITEM_H
#define SPRITEGRAPHICSITEM_H

#include <QGraphicsItem>
#include "Sprite.h"

class SpriteGraphicsItem : public QGraphicsItem
{
public:
    SpriteGraphicsItem(const Sprite& sprite);
    void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget = nullptr)override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event)override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event)override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event)override;
    QRectF boundingRect()const override;
    Sprite& GetSprite();
private:
    Sprite sprite;
};

#endif // SPRITEGRAPHICSITEM_H
