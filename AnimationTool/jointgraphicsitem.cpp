#include "jointgraphicsitem.h"
#include "QPainter"
#include "zorder.h"
#include "QGraphicsSceneDragDropEvent"
#include "QDebug"
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"

#define RADIUS 10.0

JointGraphicsItem::JointGraphicsItem(QSharedPointer<Joint> joint,bool isForBindPoseGenerator)
    :QGraphicsItem(),joint(joint),isForBindPoseGenerator(isForBindPoseGenerator)
{
    setZValue(JointZValue);
    setPos(joint->position[0],joint->position[1]);
    setFlag(ItemIsMovable);
    setAcceptDrops(true);
}

void JointGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //draw circle and joint name.
    painter->setPen(QColor().black());
    painter->drawEllipse(-RADIUS,-RADIUS,RADIUS*2.0,RADIUS*2.0);
    painter->scale(1,-1);
    painter->drawText(-RADIUS,-RADIUS,joint->name);
    BindPoseAnimSampleGeneratorGraphicsView* view = static_cast<BindPoseAnimSampleGeneratorGraphicsView*>(scene()->views()[0]);
    qreal widthPixel = view->GetWidthPixel();
    qreal heightPixel = view->GetHeightPixel();
    qreal onePixelWidth = view->viewport()->width() / widthPixel;
    qreal onePixelHeight = view->viewport()->height() / heightPixel;
    painter->drawText(-RADIUS,RADIUS * 2.5,QString::number(int(x()/onePixelWidth))+","+QString::number(int(y()/onePixelHeight)));
}

void JointGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void JointGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    if(isForBindPoseGenerator)
    {
        BindPoseAnimSampleGeneratorGraphicsView* view = static_cast<BindPoseAnimSampleGeneratorGraphicsView*>(scene()->views()[0]);
        int widthPixel = view->GetWidthPixel();
        int heightPixel = view->GetHeightPixel();
        float onePixelWidth = static_cast<float>(view->viewport()->width())/static_cast<float>(widthPixel);
        float onePixelHeight = static_cast<float>(view->viewport()->height()/static_cast<float>(heightPixel));
        float newPosX = pos().rx()-fmod(pos().rx(),onePixelWidth);
        float newPosY = pos().ry()-fmod(pos().ry(),onePixelHeight);
        setPos(std::clamp(newPosX,0.f,static_cast<float>(view->viewport()->width())),std::clamp(newPosY,0.f,static_cast<float>(view->viewport()->height())));
    }
    update();
}

void JointGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    joint->position = Vector3D{event->scenePos().x(),event->scenePos().y()};
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}


QRectF JointGraphicsItem::boundingRect() const
{
    //enough space for name length.
    return QRectF(-RADIUS*2,-RADIUS*3,RADIUS*10.0,RADIUS*10.0);
}

QSharedPointer<Joint> JointGraphicsItem::GetJoint() const
{
    return joint;
}
