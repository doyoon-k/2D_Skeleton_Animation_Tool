#include "spritegraphicsitem.h"
#include "zorder.h"
#include "QPainter"
#include "jointgraphicsitem.h"
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include <QGraphicsSceneMouseEvent>
#include "Vector3D.h"
#include "Sprite.h"

SpriteGraphicsItem::SpriteGraphicsItem(QSharedPointer<Sprite> sprite,bool isForBindPoseGenerator)
    :sprite(sprite),isForBindPoseGenerator(isForBindPoseGenerator)
{
    setZValue(TextureZValue);
    setPos(sprite->bottomLeftCoord[0],sprite->bottomLeftCoord[1]);
    setFlag(ItemIsMovable);
    setAcceptDrops(true);
}

void SpriteGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(isForBindPoseGenerator)
    {
        KeepSpriteInJointBoundingArea();
    }
    painter->setPen(QColor().black());
    const QRectF& target = QRectF(0,0,sprite->image.width(),sprite->image.height());
    const QRectF& source = QRectF(0,0,sprite->image.width(),sprite->image.height());
    painter->scale(1,-1);
    painter->translate(0,-sprite->image.height());
    painter->drawImage(target,sprite->image,source);
    painter->scale(0.5,0.5);
    painter->drawText(0,sprite->image.height()*2+10.,sprite->name);
    BindPoseAnimSampleGeneratorGraphicsView* view = static_cast<BindPoseAnimSampleGeneratorGraphicsView*>(scene()->views()[0]);
    qreal widthPixel = view->GetWidthPixel();
    qreal heightPixel = view->GetHeightPixel();
    qreal onePixelWidth = view->viewport()->width() / widthPixel;
    qreal onePixelHeight = view->viewport()->height() / heightPixel;
    painter->drawText(0,sprite->image.height()*2+30.,QString::number(int(x()/onePixelWidth))+","+QString::number(int(y()/onePixelHeight)));
}

void SpriteGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void SpriteGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    if(isForBindPoseGenerator)
    {
        KeepSpriteInJointBoundingArea();
        BindPoseAnimSampleGeneratorGraphicsView* view = static_cast<BindPoseAnimSampleGeneratorGraphicsView*>(scene()->views()[0]);
        int widthPixel = view->GetWidthPixel();
        int heightPixel = view->GetHeightPixel();
        float onePixelWidth = static_cast<float>(view->viewport()->width())/static_cast<float>(widthPixel);
        float onePixelHeight = static_cast<float>(view->viewport()->height()/static_cast<float>(heightPixel));
        float newPosX = pos().rx()-fmod(pos().rx(),onePixelWidth);
        float newPosY = pos().ry()-fmod(pos().ry(),onePixelHeight);
        setPos(std::clamp(newPosX,0.f,static_cast<float>(view->viewport()->width())),std::clamp(newPosY,0.f,static_cast<float>(view->viewport()->height()-sprite->image.height()*onePixelHeight)));
    }
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
    return QRectF(0,-50,sprite->image.width(),sprite->image.height()+50);
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

    qreal scaleX = (view->viewport()->width()/qreal(view->GetWidthPixel()));
    qreal scaleY = (view->viewport()->height()/qreal(view->GetHeightPixel()));
    qreal scaledImageWidth = sprite->image.width() * scaleX;
    qreal scaledImageHeight = sprite->image.height() * scaleY;
    qreal xPos = std::clamp(pos().rx(),JointItem->pos().rx()-scaledImageWidth,JointItem->pos().rx());
    qreal yPos = std::clamp(pos().ry(),JointItem->pos().ry()-scaledImageHeight,JointItem->pos().ry());
    setPos(xPos,yPos);
}
