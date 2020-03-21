#include "bindposeanimsamplegeneratorgraphicsview.h"
#include <QAction>
#include <QMenu>
#include <QDebug>
#include <QContextMenuEvent>
#include <QApplication>

BindPoseAnimSampleGeneratorGraphicsView::BindPoseAnimSampleGeneratorGraphicsView(QWidget *parent)
    :QGraphicsView(parent)
{
    createJointAction = new QAction(tr("&Create Joint"),this);
    jointCreateMenu = new QMenu(this);
    jointCreateMenu->addAction(createJointAction);
    jointCreateMenu->show();

    connect(createJointAction,SIGNAL(triggered()),this,SLOT(Test()));
}

void BindPoseAnimSampleGeneratorGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
         qDebug()<<"mousePressed";
         QMenu* menu = new QMenu(this);
         menu->addAction(createJointAction);
         menu->popup(mapToGlobal(event->pos()));
    }
}

void BindPoseAnimSampleGeneratorGraphicsView::Test()
{
    qDebug()<<"action Triggered!";
}


