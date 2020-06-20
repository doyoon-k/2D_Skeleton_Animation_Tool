#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QAction>
#include <QSpinBox>
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include "BindPoseGenerator/skeletonhierarchytreewidget.h"
#include "BindPoseGenerator/spritelistwidget.h"
#include <QDebug>
#include "mainwindow.h"
#include "Sprite.h"

BindPoseAnimSampleGenerator::BindPoseAnimSampleGenerator(QWidget *parent)
    : QWidget(parent),undoStack(new QUndoStack(this))
{
    CreateActions();
}

void BindPoseAnimSampleGenerator::AddJoint(QSharedPointer<Joint> joint)
{
    graphicsView->AddJoint(joint);
    skeleonHierarchyTreeWidget->AddJoint(joint);
}

void BindPoseAnimSampleGenerator::RemoveJoint(QSharedPointer<Joint> joint)
{
    graphicsView->RemoveJoint(joint.data());
    skeleonHierarchyTreeWidget->RemoveJoint(joint.data());
}

void BindPoseAnimSampleGenerator::AddSprite(QSharedPointer<Sprite> sprite)
{
    graphicsView->AddSprite(sprite);
    spriteListWidget->AddSprite(sprite.data());
}

void BindPoseAnimSampleGenerator::RemoveSprite(QSharedPointer<Sprite> sprite)
{
    graphicsView->RemoveSprite(sprite.data());
    spriteListWidget->RemoveSprite(sprite.data());
    MainWindow::RemoveSpriteNamePathPair(sprite->name);
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

BindPoseAnimSampleGeneratorGraphicsView *BindPoseAnimSampleGenerator::GetGraphicsView()
{
    return graphicsView;
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

