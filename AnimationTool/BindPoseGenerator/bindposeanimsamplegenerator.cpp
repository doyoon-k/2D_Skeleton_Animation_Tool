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
#include "BindPoseGenerator/removejointcommand.h"
#include "BindPoseGenerator/removespritecommand.h"
#include "QDebug"

BindPoseAnimSampleGenerator::BindPoseAnimSampleGenerator(QWidget *parent)
    : QWidget(parent),undoStack(new QUndoStack(this))
{
    CreateActions();
    connect(undoAction,SIGNAL(triggered()),undoStack,SLOT(undo()));
    connect(redoAction,SIGNAL(triggered()),undoStack,SLOT(redo()));
}

void BindPoseAnimSampleGenerator::AddJoint(QSharedPointer<Joint> joint)
{
    undoStack->push(new AddJointCommand(this,joint));
}

void BindPoseAnimSampleGenerator::RemoveJoint(QSharedPointer<Joint> joint)
{
    undoStack->push(new RemoveJointCommand(this,joint));
}

void BindPoseAnimSampleGenerator::AddSprite(QSharedPointer<Sprite> sprite)
{
    undoStack->push(new AddSpriteCommand(this,sprite));
}

void BindPoseAnimSampleGenerator::RemoveSprite(QSharedPointer<Sprite> sprite)
{
    undoStack->push(new RemoveSpriteCommand(this,sprite));
}

void BindPoseAnimSampleGenerator::SetJointName(const Joint& joint,QString name)
{
    graphicsView->SetJointName(joint,name);
}

void BindPoseAnimSampleGenerator::SetSpriteName(const Sprite &sprite, QString name)
{
    graphicsView->SetSpriteName(sprite,name);
}

void BindPoseAnimSampleGenerator::ConnectSpinboxSignals()
{
    connect(widthPixelSpinBox,SIGNAL(valueChanged(int)),graphicsView,SLOT(setWidthPixel(int)));
    connect(heightPixelSpinBox,SIGNAL(valueChanged(int)),graphicsView,SLOT(setHeightPixel(int)));
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

