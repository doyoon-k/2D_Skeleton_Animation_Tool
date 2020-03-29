#include "BindPoseGenerator/addjointcommand.h"
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include "BindPoseGenerator/skeletonhierarchytreewidget.h"

AddJointCommand::AddJointCommand(BindPoseAnimSampleGenerator* bindPoseAnimSanpleGeneratorWidget,const Joint& joint)
    :QUndoCommand("Add joint"),joint(joint),bindPoseAnimSanpleGeneratorWidget(bindPoseAnimSanpleGeneratorWidget)
{

}

void AddJointCommand::undo()
{
    bindPoseAnimSanpleGeneratorWidget->RemoveJoint(joint);
}

void AddJointCommand::redo()
{
    bindPoseAnimSanpleGeneratorWidget->graphicsView->AddJoint(joint);
    bindPoseAnimSanpleGeneratorWidget->skeleonHierarchyTreeWidget->AddJoint(joint);
}
