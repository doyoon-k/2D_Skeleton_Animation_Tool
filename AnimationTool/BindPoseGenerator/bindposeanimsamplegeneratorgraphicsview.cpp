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
#include "BindPoseGenerator/spritecreatedialog.h"
#include <QResource>
#include <QMessageBox>
#include "Sprite.h"

BindPoseAnimSampleGeneratorGraphicsView::BindPoseAnimSampleGeneratorGraphicsView(QWidget *parent)
    :QGraphicsView(parent),scene(new QGraphicsScene(this))
{
    this->parent = static_cast<BindPoseAnimSampleGenerator*>(parent);
    setScene(scene);
    CreateActionMenu();
    connect(createJointAction,SIGNAL(triggered()),this,SLOT(SignalAddJointToAnimSampleGeneratorWidget()));
    connect(createSpriteAction,SIGNAL(triggered()),this,SLOT(SignalAddSpriteToAnimSampleGeneratorWidget()));
    scale(1,-1);
    setAcceptDrops(true);
    setMouseTracking(true);
}

void BindPoseAnimSampleGeneratorGraphicsView::mousePressEvent(QMouseEvent *event)
{
    mouseRightClickEventPos = event->pos();
    if(event->button() == Qt::RightButton)
    {
         qDebug()<<"mousePressed" << " : " << mouseRightClickEventPos;
         joint_sprite_CreateMenu->popup(mapToGlobal(event->pos()));
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
    pen.setWidth(1);
    skeletonSpaceOrigin = scene->addRect(0,0,qreal( viewport()->width())/qreal(widthPixel),qreal( viewport()->height())/qreal(heightPixel),pen);
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
    createSpriteAction = new QAction(tr("&Create Sprite"),this);
    joint_sprite_CreateMenu = new QMenu(this);
    joint_sprite_CreateMenu->addAction(createJointAction);
    joint_sprite_CreateMenu->addAction(createSpriteAction);
}

void BindPoseAnimSampleGeneratorGraphicsView::RescaleGraphicsItems()
{
    QTransform transform;
    qreal scaleX = (viewport()->width()/qreal(widthPixel))/skeletonSpaceOrigin->boundingRect().width();
    qreal scaleY = (viewport()->height()/qreal(heightPixel))/skeletonSpaceOrigin->boundingRect().height();
    transform.scale(scaleX,scaleY);
    skeletonSpaceOrigin->setTransform(transform);
    for(SpriteGraphicsItem* spriteItem : spriteGraphicsItems)
    {
        QTransform transform;
        qreal scaleX = (viewport()->width()/qreal(widthPixel));
        qreal scaleY = (viewport()->height()/qreal(heightPixel));
        transform.scale(scaleX,scaleY);
        spriteItem->setTransform(transform);
    }
}

void BindPoseAnimSampleGeneratorGraphicsView::AddJoint(QSharedPointer<Joint> joint)
{
    JointGraphicsItem* jointItem = new JointGraphicsItem(joint);
    jointGraphicsItems.push_back(jointItem);
    scene->addItem(jointItem);
    RescaleGraphicsItems();
    update();
}

void BindPoseAnimSampleGeneratorGraphicsView::RemoveJoint(Joint* joint)
{
    JointGraphicsItem* jointGraphicsItem = GetJointGraphicsItemByName(joint->name);
    if(jointGraphicsItem == nullptr)
    {
        qDebug()<<"no such joint";
        return;
    }

    jointGraphicsItems.removeOne(jointGraphicsItem);
    scene->removeItem(jointGraphicsItem);
    update();
}

void BindPoseAnimSampleGeneratorGraphicsView::SetJointName(const Joint& joint,QString newName)
{
    JointGraphicsItem* jointItem = GetJointGraphicsItemByName(joint.name);
    if(jointItem == nullptr)
    {
        qDebug()<<"no such joint item";
        return;
    }

    jointItem->GetJoint()->name = newName;
    scene->update(sceneRect());
}

void BindPoseAnimSampleGeneratorGraphicsView::AddSprite(QSharedPointer<Sprite> sprite)
{
    SpriteGraphicsItem* spriteGraphicsItem = new SpriteGraphicsItem(sprite);
    spriteGraphicsItems.push_back(spriteGraphicsItem);
    scene->addItem(spriteGraphicsItem);
    RescaleGraphicsItems();
    update();
}

void BindPoseAnimSampleGeneratorGraphicsView::RemoveSprite(Sprite* sprite)
{
    SpriteGraphicsItem* spriteGraphicsItem = GetSpriteGraphicsItemByName(sprite->name);
    if(spriteGraphicsItem == nullptr)
    {
        qDebug()<<"no such sprite";
        return;
    }

    spriteGraphicsItems.removeOne(spriteGraphicsItem);
    scene->removeItem(spriteGraphicsItem);
    update();
}

void BindPoseAnimSampleGeneratorGraphicsView::SetSpriteName(const Sprite &sprite,QString newName)
{
    SpriteGraphicsItem* spriteGraphicsItem = GetSpriteGraphicsItemByName(sprite.name);
    if(spriteGraphicsItem == nullptr)
    {
        qDebug()<<"no such sprite";
        return;
    }

    spriteGraphicsItem->GetSprite()->name = newName;
    scene->update(sceneRect());
}

void BindPoseAnimSampleGeneratorGraphicsView::SetSpriteGraphicsItemsOpacity(qreal opacity)
{
    for(SpriteGraphicsItem* item : spriteGraphicsItems)
    {
        item->setOpacity(opacity);
    }
}

void BindPoseAnimSampleGeneratorGraphicsView::paintEvent(QPaintEvent *event)
{
    QGraphicsView::paintEvent(event);
}

int BindPoseAnimSampleGeneratorGraphicsView::GetWidthPixel() const
{
    return widthPixel;
}

int BindPoseAnimSampleGeneratorGraphicsView::GetHeightPixel() const
{
    return heightPixel;
}

qreal BindPoseAnimSampleGeneratorGraphicsView::GetScalarWidthPixel()
{
    qreal scaleX = (viewport()->width()/qreal(widthPixel));
    return scaleX;
}

qreal BindPoseAnimSampleGeneratorGraphicsView::GetScalarHeightPixel()
{
    qreal scaleY = (viewport()->height()/qreal(heightPixel));
    return scaleY;
}

JointGraphicsItem *BindPoseAnimSampleGeneratorGraphicsView::GetJointGraphicsItemByName(const QString& jointName)
{
    for(JointGraphicsItem* jointItem : jointGraphicsItems)
    {
        QSharedPointer<Joint> Joint = jointItem->GetJoint();
        if(Joint->name == jointName)
        {
            return jointItem;
        }
    }
    return nullptr;
}

SpriteGraphicsItem *BindPoseAnimSampleGeneratorGraphicsView::GetSpriteGraphicsItemByName(const QString& spriteName)
{
    for(SpriteGraphicsItem* spriteItem : spriteGraphicsItems)
    {
        QSharedPointer<Sprite> Sprite = spriteItem->GetSprite();
        if(Sprite->name == spriteName)
        {
            return spriteItem;
        }
    }
    return nullptr;
}

void BindPoseAnimSampleGeneratorGraphicsView::SignalAddJointToAnimSampleGeneratorWidget()
{
    //height - y because of the difference of coordinate system.
    Vector3D jointPos{mouseRightClickEventPos.x(),height()-mouseRightClickEventPos.y()};
    QSharedPointer<Joint> joint{new Joint{0,jointPos,"TEMP"}};
    parent->AddJoint(joint);
}

void BindPoseAnimSampleGeneratorGraphicsView::SignalAddSpriteToAnimSampleGeneratorWidget()
{
    QGraphicsItem* item = itemAt(mouseRightClickEventPos);
    if(item == nullptr)
    {
        QMessageBox msgBox;
        msgBox.setText("No joint at desired position.");
        msgBox.exec();
        return;
    }

    SpriteCreateDialog dialog(parent->imagesListWidget);
    dialog.exec();
    if(dialog.IsSpriteCreated())
    {
        //no worry for getting sprite item because joint item z value is higher.
        QSharedPointer<Joint> parentJoint = static_cast<JointGraphicsItem*>(item)->GetJoint();
        QString spriteName = dialog.GetCreatedSpriteName();
        QString imagePath = dialog.GetSelectedImagePath();
        Vector3D position = {mouseRightClickEventPos.x(),height()-mouseRightClickEventPos.y()};
        //final connectedJointIndex will be decided at the save process.
        QSharedPointer<Sprite> sprite{new Sprite{parentJoint,0,spriteName,position,0.f,QImage(imagePath)}};
        parent->AddSprite(sprite);
        qDebug()<<"sprite created!"<<'\n';
    }
//    parent->AddSprite(sprite);
}

void BindPoseAnimSampleGeneratorGraphicsView::setWidthPixel(int val)
{
    widthPixel = val;
    viewport()->repaint(viewport()->rect());
    RescaleGraphicsItems();
}

void BindPoseAnimSampleGeneratorGraphicsView::setHeightPixel(int val)
{
    heightPixel = val;
    viewport()->repaint(viewport()->rect());
    RescaleGraphicsItems();
}
