#include "BindPoseGenerator/addjointcommand.h"
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "BindPoseGenerator/skeletonhierarchytreewidget.h"

AddJointCommand::AddJointCommand(BindPoseAnimSampleGenerator* bindPoseAnimSanpleGeneratorWidget,QSharedPointer<Joint> joint)
    :QUndoCommand("Add joint"),joint(joint),bindPoseAnimSanpleGeneratorWidget(bindPoseAnimSanpleGeneratorWidget)
{

}

void AddJointCommand::undo()
{
    bindPoseAnimSanpleGeneratorWidget->graphicsView->RemoveJoint(joint.data());
    bindPoseAnimSanpleGeneratorWidget->skeleonHierarchyTreeWidget->RemoveJoint(joint.data());
}

void AddJointCommand::redo()
{
    bindPoseAnimSanpleGeneratorWidget->graphicsView->AddJoint(joint);
    bindPoseAnimSanpleGeneratorWidget->skeleonHierarchyTreeWidget->AddJoint(joint);
}
