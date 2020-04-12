#include "removejointcommand.h"
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "BindPoseGenerator/skeletonhierarchytreewidget.h"

RemoveJointCommand::RemoveJointCommand(BindPoseAnimSampleGenerator *bindPoseAnimSampleGeneratorWidget,QSharedPointer<Joint> joint)
    :QUndoCommand ("Remove Joint"),joint(joint),bindPoseAnimSampleGeneratorWidget(bindPoseAnimSampleGeneratorWidget)
{

}

void RemoveJointCommand::undo()
{
    bindPoseAnimSampleGeneratorWidget->graphicsView->AddJoint(joint);
    bindPoseAnimSampleGeneratorWidget->skeleonHierarchyTreeWidget->AddJoint(joint);
}

void RemoveJointCommand::redo()
{
    bindPoseAnimSampleGeneratorWidget->graphicsView->RemoveJoint(joint.data());
    bindPoseAnimSampleGeneratorWidget->skeleonHierarchyTreeWidget->RemoveJoint(joint.data());
}
