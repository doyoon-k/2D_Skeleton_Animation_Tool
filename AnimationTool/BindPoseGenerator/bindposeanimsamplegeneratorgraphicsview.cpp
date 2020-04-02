#include <BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h>
#include <QAction>
#include <QMenu>
#include <QDebug>
#include <QContextMenuEvent>
#include <QApplication>
#include <BindPoseGenerator/bindposeanimsamplegenerator.h>
#include <QGraphicsEllipseItem>
#include "jointgraphicsitem.h"
#include "spritegraphicsitem.h"

BindPoseAnimSampleGeneratorGraphicsView::BindPoseAnimSampleGeneratorGraphicsView(QWidget *parent)
    :QGraphicsView(parent),scene(new QGraphicsScene(this))
{
    this->parent = static_cast<BindPoseAnimSampleGenerator*>(parent);
    setScene(scene);
    CreateActionMenu();
    connect(createJointAction,SIGNAL(triggered()),this,SLOT(SignalAddJointToAnimSampleGeneratorWidget()));
    scale(1,-1);
    setAcceptDrops(true);
    setMouseTracking(true);
}

void BindPoseAnimSampleGeneratorGraphicsView::mousePressEvent(QMouseEvent *event)
{
    mouseEventPos = event->pos();
    if(event->button() == Qt::RightButton)
    {
         qDebug()<<"mousePressed";
         jointCreateMenu->popup(mapToGlobal(event->pos()));
    }
    QGraphicsView::mousePressEvent(event);
}

void BindPoseAnimSampleGeneratorGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
}

void BindPoseAnimSampleGeneratorGraphicsView::showEvent(QShowEvent *event)
{
    scene->setSceneRect(0,0,this->width(),this->height());

    QPen pen(QColor(255,0,0));
    pen.setWidth(20);
    skeletonSpaceOrigin = scene->addEllipse(-10,-10,20,20,pen);
    skeletonSpaceOrigin->setPos(0,0);
}

void BindPoseAnimSampleGeneratorGraphicsView::resizeEvent(QResizeEvent *event)
{
    scene->setSceneRect(0,0,this->width(),this->height());
    update();
}

void BindPoseAnimSampleGeneratorGraphicsView::CreateActionMenu()
{
    createJointAction = new QAction(tr("&Create Joint"),this);
    jointCreateMenu = new QMenu(this);
    jointCreateMenu->addAction(createJointAction);
}

void BindPoseAnimSampleGeneratorGraphicsView::AddJoint(const Joint& joint)
{
    JointGraphicsItem* jointItem = new JointGraphicsItem(joint);
    jointGraphicsItems.push_back(jointItem);
    scene->addItem(jointItem);
    update();
}

void BindPoseAnimSampleGeneratorGraphicsView::RemoveJoint(const Joint &joint)
{
    JointGraphicsItem* jointGraphicsItem = GetJointGraphicsItemByName(joint);
    if(jointGraphicsItem == nullptr)
    {
        qDebug()<<"no such joint";
        return;
    }

    jointGraphicsItems.removeOne(jointGraphicsItem);
    scene->removeItem(jointGraphicsItem);
    update();
}

void BindPoseAnimSampleGeneratorGraphicsView::SetJointName(const Joint& joint,QString name)
{
    JointGraphicsItem* jointItem = GetJointGraphicsItemByName(joint);
    if(jointItem == nullptr)
    {
        qDebug()<<"no such joint item";
        return;
    }

    jointItem->GetJoint().name = name;
    scene->update(sceneRect());
}

void BindPoseAnimSampleGeneratorGraphicsView::AddSprite(const Sprite &sprite)
{

}

void BindPoseAnimSampleGeneratorGraphicsView::RemoveSprite(const Sprite &sprite)
{

}

void BindPoseAnimSampleGeneratorGraphicsView::SetSpriteName(const Sprite &sprite)
{

}

void BindPoseAnimSampleGeneratorGraphicsView::paintEvent(QPaintEvent *event)
{
    QGraphicsView::paintEvent(event);
    QPainter painter(viewport());
    painter.setPen(QColor(255));
    float onePixelWidth = static_cast<float>(width()) / static_cast<float>(widthPixel);
    float onePixelHeight = static_cast<float>(height()) / static_cast<float>(heightPixel);
    for(int i = 0; i < widthPixel; i++)
    {
       painter.drawLine(QPointF(onePixelWidth*i,0),QPointF(onePixelWidth*i,height()));
    }
    for(int j = 0; j < heightPixel; j++)
    {
        painter.drawLine(QPointF(0,onePixelHeight*j),QPointF(width(),onePixelHeight*j));
    }
}

int BindPoseAnimSampleGeneratorGraphicsView::GetWidthPixel() const
{
    return widthPixel;
}

int BindPoseAnimSampleGeneratorGraphicsView::GetHeightPixel() const
{
    return heightPixel;
}

JointGraphicsItem *BindPoseAnimSampleGeneratorGraphicsView::GetJointGraphicsItemByName(const Joint &joint)
{
    for(JointGraphicsItem* jointItem : jointGraphicsItems)
    {
        Joint& Joint = jointItem->GetJoint();
        if(Joint.name == joint.name)
        {
            return jointItem;
        }
    }
    return nullptr;
}

SpriteGraphicsItem *BindPoseAnimSampleGeneratorGraphicsView::GetSpriteGraphicsItemByName(const Sprite &sprite)
{
    for(SpriteGraphicsItem* spriteItem : spriteGraphicsItems)
    {
        Sprite& Sprite = spriteItem->GetSprite();
        if(Sprite.name == sprite.name)
        {
            return spriteItem;
        }
    }
    return nullptr;
}

void BindPoseAnimSampleGeneratorGraphicsView::SignalAddJointToAnimSampleGeneratorWidget()
{
    //height - y because of the difference of coordinate system.
    Vector3D jointPos{mouseEventPos.x(),height()-mouseEventPos.y()};
    Joint joint{0,jointPos,"TEMP"};
    parent->AddJoint(joint);
}

void BindPoseAnimSampleGeneratorGraphicsView::setWidthPixel(int val)
{
    widthPixel = val;
    viewport()->repaint(viewport()->rect());
}

void BindPoseAnimSampleGeneratorGraphicsView::setHeightPixel(int val)
{
    heightPixel = val;
    viewport()->repaint(viewport()->rect());
}
