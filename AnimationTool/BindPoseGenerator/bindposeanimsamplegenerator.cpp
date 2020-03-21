#include "bindposeanimsamplegenerator.h"
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QAction>
#include "bindposeanimsamplegeneratorgraphicsview.h"

BindPoseAnimSampleGenerator::BindPoseAnimSampleGenerator(QWidget *parent)
    : QWidget(parent),undoStack(new QUndoStack(this))
{
    CreateActions();
    connect(undoAction,SIGNAL(triggered()),undoStack,SLOT(undo()));
    connect(redoAction,SIGNAL(triggered()),undoStack,SLOT(redo()));
}

void BindPoseAnimSampleGenerator::AddJoint(const Joint& joint)
{
    graphicsView->AddJoint(joint);

}

void BindPoseAnimSampleGenerator::CreateActions()
{
    undoAction = new QAction(tr("&Undo"),this);
    redoAction = new QAction(tr("&Redo"),this);
    undoAction->setShortcut(QKeySequence::Undo);
    undoAction->setShortcut(QKeySequence::Redo);
}
