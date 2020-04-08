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
    createSpriteAction = new QAction(tr("&Create Sprite"),this);
    joint_sprite_CreateMenu = new QMenu(this);
    joint_sprite_CreateMenu->addAction(createJointAction);
    joint_sprite_CreateMenu->addAction(createSpriteAction);
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
    JointGraphicsItem* jointGraphicsItem = GetJointGraphicsItem(joint);
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
    JointGraphicsItem* jointItem = GetJointGraphicsItem(joint);
    if(jointItem == nullptr)
    {
        qDebug()<<"no such joint item";
        return;
    }

    jointItem->GetJoint().name = newName;
    scene->update(sceneRect());
}

void BindPoseAnimSampleGeneratorGraphicsView::AddSprite(const Sprite &sprite)
{
    SpriteGraphicsItem* spriteGraphicsItem = new SpriteGraphicsItem(sprite);
    spriteGraphicsItems.push_back(spriteGraphicsItem);
    scene->addItem(spriteGraphicsItem);
    update();
}

void BindPoseAnimSampleGeneratorGraphicsView::RemoveSprite(const Sprite &sprite)
{
    SpriteGraphicsItem* spriteGraphicsItem = GetSpriteGraphicsItem(sprite);
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

JointGraphicsItem *BindPoseAnimSampleGeneratorGraphicsView::GetJointGraphicsItem(const Joint &joint)
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

SpriteGraphicsItem *BindPoseAnimSampleGeneratorGraphicsView::GetSpriteGraphicsItem(const Sprite &sprite)
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
    Vector3D jointPos{mouseRightClickEventPos.x(),height()-mouseRightClickEventPos.y()};
    Joint joint{0,jointPos,"TEMP"};
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
        Joint parentJoint = static_cast<JointGraphicsItem*>(item)->GetJoint();
        QString spriteName = dialog.GetCreatedSpriteName();
        QString imagePath = dialog.GetSelectedImagePath();
        Vector3D position = {mouseRightClickEventPos.x(),height()-mouseRightClickEventPos.y()};
        //final connectedJointIndex will be decided at the save process.
        Sprite sprite{parentJoint,0,spriteName,position,0.f,QImage(imagePath)};
        parent->AddSprite(sprite);
        qDebug()<<"sprite created!"<<'\n';
    }
//    parent->AddSprite(sprite);
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
