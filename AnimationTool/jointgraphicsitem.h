#pragma once
#ifndef JOINTGRAPHICSITEM_H
#define JOINTGRAPHICSITEM_H
#include "QGraphicsItem"
#include "Joint.h"

class JointGraphicsItem : public QGraphicsItem
{
public:
    JointGraphicsItem(QSharedPointer<Joint> joint);
    void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget = nullptr)override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event)override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)override;
    QRectF boundingRect()const override;
    QSharedPointer<Joint> GetJoint();
private:
    QSharedPointer<Joint> joint;
};

#endif // JOINTGRAPHICSITEM_H
