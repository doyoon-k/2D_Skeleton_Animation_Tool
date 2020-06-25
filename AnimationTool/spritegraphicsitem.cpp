#include "spritegraphicsitem.h"
#include "zorder.h"
#include "QPainter"
#include "jointgraphicsitem.h"
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include <QGraphicsSceneMouseEvent>
#include "Vector3D.h"
#include "Sprite.h"
#include "Matrix3X3.h"
#include <QDebug>
#include "animsampleeditorgraphicsview.h"
#include <QtMath>

SpriteGraphicsItem::SpriteGraphicsItem(QSharedPointer<Sprite> sprite,bool isForBindPoseGenerator)
    :sprite(sprite),isForBindPoseGenerator(isForBindPoseGenerator)
{
    prepareGeometryChange();
    setZValue(TextureZValue);
    setPos(sprite->bottomLeftCoord[0],sprite->bottomLeftCoord[1]);
    setFlag(ItemIsMovable);
    setAcceptDrops(true);
}

void SpriteGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    prepareGeometryChange();
    painter->drawRect(boundingRect());
    painter->scale(1,-1);
    float rotationRad = (sprite->rotationOffset < 3.141592f) ? sprite->rotationOffset : -(6.283185f-sprite->rotationOffset);
    qreal heightScale = transform().m22();
    qreal widthScale = transform().m11();
    painter->scale(1.0/widthScale,1.0/heightScale);
    painter->rotate(-rotationRad*180.f/3.141592f);
    painter->scale(widthScale,heightScale);
    painter->translate(0,-sprite->image.height());
    painter->drawImage(QPointF(0,0),sprite->image);
    painter->scale(0.5,0.5);
    if(isForBindPoseGenerator)
    {
    painter->drawText(0,sprite->image.height()*2+10.,sprite->name);
    BindPoseAnimSampleGeneratorGraphicsView* view = static_cast<BindPoseAnimSampleGeneratorGraphicsView*>(scene()->views()[0]);
    qreal widthPixel = view->GetWidthPixel();
    qreal heightPixel = view->GetHeightPixel();
    qreal onePixelWidth = view->viewport()->width() / widthPixel;
    qreal onePixelHeight = view->viewport()->height() / heightPixel;
    painter->drawText(0,sprite->image.height()*2+30.,QString::number(x()/onePixelWidth)+","+QString::number(y()/onePixelHeight));
    }
}

void SpriteGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    prepareGeometryChange();
    update();
    QGraphicsItem::mousePressEvent(event);
}

void SpriteGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    prepareGeometryChange();
    QGraphicsItem::mouseMoveEvent(event);
    update();
}

void SpriteGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    prepareGeometryChange();
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

QRectF SpriteGraphicsItem::boundingRect() const
{
    qreal heightScale = transform().m22();
    qreal widthScale = transform().m11();

    Vector3D topLeft(0,-20);
    Vector3D topRight(sprite->image.width(),-20);
    Vector3D bottomRight(sprite->image.width(),sprite->image.height());
    Vector3D bottomLeft(0,sprite->image.height());
    if(!isForBindPoseGenerator)
    {
        topLeft = Vector3D(0,0);
        topRight = Vector3D(sprite->image.width(),0);
    }

    Matrix3X3 rotationMatrix = Matrix3X3::GetRotationMatrix(-sprite->rotationOffset);
    topLeft = rotationMatrix*topLeft;
    topRight = rotationMatrix*topRight;
    bottomLeft = rotationMatrix*bottomLeft;
    bottomRight = rotationMatrix*bottomRight;

    QPointF finalTopLeft;
    finalTopLeft.setX(std::min({topLeft[0],topRight[0],bottomLeft[0],bottomRight[0]}));
    finalTopLeft.setY(std::min({topLeft[1],topRight[1],bottomLeft[1],bottomRight[1]}));
    QPointF finalBottomRight;
    finalBottomRight.setX(std::max({topLeft[0],topRight[0],bottomLeft[0],bottomRight[0]}));
    finalBottomRight.setY(std::max({topLeft[1],topRight[1],bottomLeft[1],bottomRight[1]}));

    return QRectF(finalTopLeft,finalBottomRight);
}

QSharedPointer<Sprite> SpriteGraphicsItem::GetSprite()
{
    return sprite;
}

