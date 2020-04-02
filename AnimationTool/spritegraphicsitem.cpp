#include "spritegraphicsitem.h"
#include "zorder.h"
#include "QPainter"
#include "jointgraphicsitem.h"

SpriteGraphicsItem::SpriteGraphicsItem(const Sprite &sprite)
    :sprite(sprite)
{
    setZValue(TextureZValue);
    setPos(sprite.bottomLeftCoord[0],sprite.bottomLeftCoord[1]);
    setFlag(ItemIsMovable);
    setAcceptDrops(true);
}

void SpriteGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor().black());
    const QRectF& target = QRectF(0,0,sprite.pImage->width(),sprite.pImage->height());
    const QRectF& source = QRectF(0,0,sprite.pImage->width(),sprite.pImage->height());
    painter->scale(1,-1);
    painter->drawImage(target,*(sprite.pImage),source);
    painter->drawText(0,-10,sprite.name);
}

void SpriteGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void SpriteGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    //sprite.parentJointName 으로 GraphicsView에서 JointItem 가져와서 스프라이트 테두리가 그 조인트 위에 있도록 고정하기.
//    JointGraphicsItem* jointItem =
}

void SpriteGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

QRectF SpriteGraphicsItem::boundingRect() const
{
    return QRectF(0,-10,sprite.pImage->width(),sprite.pImage->height()+10);
}

Sprite &SpriteGraphicsItem::GetSprite()
{
    return sprite;
}
