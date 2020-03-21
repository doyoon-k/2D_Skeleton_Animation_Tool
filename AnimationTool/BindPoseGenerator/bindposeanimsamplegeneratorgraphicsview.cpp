#include "bindposeanimsamplegeneratorgraphicsview.h"
#include <QAction>
#include <QMenu>
#include <QDebug>
#include <QContextMenuEvent>
#include <QApplication>
#include <bindposeanimsamplegenerator.h>
#include <QGraphicsEllipseItem>

BindPoseAnimSampleGeneratorGraphicsView::BindPoseAnimSampleGeneratorGraphicsView(QWidget *parent)
    :QGraphicsView(parent),scene(new QGraphicsScene(this))
{
    this->parent = static_cast<BindPoseAnimSampleGenerator*>(parent);
    setScene(scene);
    scene->setSceneRect(0,0,this->width(),this->height());
    CreateActionMenu();
    connect(createJointAction,SIGNAL(triggered()),this,SLOT(AddJointSignalToParent()));

    skeletonSpaceOrigin = scene->addEllipse(0,0,20,20,QPen(QColor(255,0,0)));
    skeletonSpaceOrigin->setPos(0,scene->height());
}

void BindPoseAnimSampleGeneratorGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
         qDebug()<<"mousePressed";
         jointCreateMenu->popup(mapToGlobal(event->pos()));
    }
}

void BindPoseAnimSampleGeneratorGraphicsView::CreateActionMenu()
{
    createJointAction = new QAction(tr("&Create Joint"),this);
    jointCreateMenu = new QMenu(this);
    jointCreateMenu->addAction(createJointAction);
}

void BindPoseAnimSampleGeneratorGraphicsView::AddJoint(const Joint& joint)
{

}

void BindPoseAnimSampleGeneratorGraphicsView::AddJointSignalToParent()
{
//    parent->AddJoint(Joint(0,));
}
