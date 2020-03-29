#ifndef JOINTGRAPHICSITEM_H
#define JOINTGRAPHICSITEM_H
#include "QGraphicsItem"
#include "Joint.h"

class JointGraphicsItem : public QGraphicsItem
{
public:
    JointGraphicsItem(const Joint& joint);
    void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget = nullptr)override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event)override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)override;
    QRectF boundingRect()const override;
    Joint& GetJoint();
private:
    Joint joint;
};

#endif // JOINTGRAPHICSITEM_H
