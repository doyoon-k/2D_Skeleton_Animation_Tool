#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QAction>
#include <QSpinBox>
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include "BindPoseGenerator/skeletonhierarchytreewidget.h"
#include "BindPoseGenerator/spritelistwidget.h"
#include "BindPoseGenerator/addjointcommand.h"
#include "BindPoseGenerator/addspritecommand.h"
#include "QDebug"

BindPoseAnimSampleGenerator::BindPoseAnimSampleGenerator(QWidget *parent)
    : QWidget(parent),undoStack(new QUndoStack(this))
{
    CreateActions();
    connect(undoAction,SIGNAL(triggered()),undoStack,SLOT(undo()));
    connect(redoAction,SIGNAL(triggered()),undoStack,SLOT(redo()));
}

void BindPoseAnimSampleGenerator::AddJoint(const Joint& joint)
{
    undoStack->push(new AddJointCommand(this,joint));
}

void BindPoseAnimSampleGenerator::RemoveJoint(const Joint &joint)
{
    graphicsView->RemoveJoint(joint);
    skeleonHierarchyTreeWidget->RemoveJoint(joint);
}

void BindPoseAnimSampleGenerator::AddSprite(const Sprite &sprite)
{
    undoStack->push(new AddSpriteCommand(this,sprite));
}

void BindPoseAnimSampleGenerator::RemoveSprite(const Sprite &sprite)
{
    graphicsView->RemoveSprite(sprite);
    spriteListWidget->RemoveSprite(sprite);
}

void BindPoseAnimSampleGenerator::SetJointName(const Joint& joint,QString name)
{
    graphicsView->SetJointName(joint,name);
}

void BindPoseAnimSampleGenerator::ConnectSpinboxSignals()
{
    connect(widthPixelSpinBox,SIGNAL(valueChanged(int)),graphicsView,SLOT(setWidthPixel(int)));
    connect(heightPixelSpinBox,SIGNAL(valueChanged(int)),graphicsView,SLOT(setHeightPixel(int)));
}

void BindPoseAnimSampleGenerator::LoadImagePath(QString path)
{

}


//Maybe consider AddJoint for redo & RemoveJoint for undo just for AddJoint and same for RemoveJoint to support joint Removal from Skeleton Hierarchy.

void BindPoseAnimSampleGenerator::CreateActions()
{
    undoAction = new QAction(tr("&Undo"),this);
    redoAction = new QAction(tr("&Redo"),this);
    undoAction->setShortcut(QKeySequence::Undo);
    redoAction->setShortcut(QKeySequence::Redo);
    addAction(undoAction);
    addAction(redoAction);
}

