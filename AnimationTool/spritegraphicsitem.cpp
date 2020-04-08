#include "spritegraphicsitem.h"
#include "zorder.h"
#include "QPainter"
#include "jointgraphicsitem.h"
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include <QGraphicsSceneMouseEvent>
#include "Vector3D.h"

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
    const QRectF& target = QRectF(0,0,sprite.image.width(),sprite.image.height());
    const QRectF& source = QRectF(0,0,sprite.image.width(),sprite.image.height());
    painter->scale(1,-1);
    painter->drawImage(target,sprite.image,source);
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
    BindPoseAnimSampleGeneratorGraphicsView* view = static_cast<BindPoseAnimSampleGeneratorGraphicsView*>(scene()->views()[0]);
    update();
}

void SpriteGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    sprite.bottomLeftCoord = Vector3D{event->scenePos().x(),event->scenePos().y()};
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

QRectF SpriteGraphicsItem::boundingRect() const
{
    return QRectF(0,-sprite.image.height(),sprite.image.width(),sprite.image.height()+30);
}

Sprite &SpriteGraphicsItem::GetSprite()
{
    return sprite;
}
