#include "BindPoseGenerator/skeletonhierarchytreewidget.h"
#include "BindPoseGenerator/jointtreewidgetitem.h"
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "QDebug"
#include "QKeyEvent"

SkeletonHierarchyTreeWidget::SkeletonHierarchyTreeWidget(QWidget* parent)
    :QTreeWidget(parent),parent(static_cast<BindPoseAnimSampleGenerator*>(parent))
{
}

void SkeletonHierarchyTreeWidget::AddJoint(const Joint &joint)
{
    JointTreeWidgetItem* item = new JointTreeWidgetItem(joint);
    addTopLevelItem(item);
}

void SkeletonHierarchyTreeWidget::RemoveJoint(const Joint &joint)
{
    //since the flag has set Match Exactly...each joint name should be different.
    QTreeWidgetItem* jointItem = findItems(joint.name,Qt::MatchExactly|Qt::MatchRecursive)[0];
    //this is proven safe by the document.
    delete jointItem;
}

void SkeletonHierarchyTreeWidget::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if(topLevelItemCount() == 0)
    {
        return;
    }

    JointTreeWidgetItem* item = static_cast<JointTreeWidgetItem*>(selectedItems()[0]);
    QString prevName = item->text(0);
    QString text = item->text(0);

    if(key == Qt::Key_Delete)
    {
        parent->RemoveJoint(item->jointData);
        return;
    }
    else if(key == Qt::Key_Backspace && text.size()> 0)
    {
        text.resize(text.size()-1);
    }
    else if((Qt::Key_0 <= key && key <= Qt::Key_9) ||
            (Qt::Key_A <= key && key <= Qt::Key_Z) ||
             key == Qt::Key_Underscore)
    {
        text.push_back(key);
    }
    item->setText(0,text);
    parent->SetJointName(item->jointData,text);
    item->jointData.name = text;
}
