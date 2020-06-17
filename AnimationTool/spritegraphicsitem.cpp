#include "spritegraphicsitem.h"
#include "zorder.h"
#include "QPainter"
#include "jointgraphicsitem.h"
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include <QGraphicsSceneMouseEvent>
#include "Vector3D.h"
#include "Sprite.h"

SpriteGraphicsItem::SpriteGraphicsItem(QSharedPointer<Sprite> sprite)
    :sprite(sprite)
{
    setZValue(TextureZValue);
    setPos(sprite->bottomLeftCoord[0],sprite->bottomLeftCoord[1]);
    setFlag(ItemIsMovable);
    setAcceptDrops(true);
}

void SpriteGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    KeepSpriteInJointBoundingArea();
    painter->setPen(QColor().black());
    const QRectF& target = QRectF(0,0,sprite->image.width(),sprite->image.height());
    const QRectF& source = QRectF(0,0,sprite->image.width(),sprite->image.height());
    painter->scale(1,-1);
    painter->translate(0,-sprite->image.height());
    painter->drawImage(target,sprite->image,source);
    painter->drawText(0,-10,sprite->name);
}

void SpriteGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void SpriteGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    KeepSpriteInJointBoundingArea();
    update();
}

void SpriteGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    sprite->bottomLeftCoord = Vector3D{event->scenePos().x(),event->scenePos().y()};
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

QRectF SpriteGraphicsItem::boundingRect() const
{
    return QRectF(0,0,sprite->image.width(),sprite->image.height()+30);
}

QSharedPointer<Sprite> SpriteGraphicsItem::GetSprite()
{
    return sprite;
}

void SpriteGraphicsItem::KeepSpriteInJointBoundingArea()
{
    BindPoseAnimSampleGeneratorGraphicsView* view = static_cast<BindPoseAnimSampleGeneratorGraphicsView*>(scene()->views()[0]);
    JointGraphicsItem* JointItem = view->GetJointGraphicsItemByName(sprite->parentJoint->name);
    if(JointItem == nullptr)
        return;
    qreal xPos = std::clamp(pos().rx(),JointItem->pos().rx()-sprite->image.width(),JointItem->pos().rx());
    qreal yPos = std::clamp(pos().ry(),JointItem->pos().ry()-sprite->image.height(),JointItem->pos().ry());
    setPos(xPos,yPos);
}
