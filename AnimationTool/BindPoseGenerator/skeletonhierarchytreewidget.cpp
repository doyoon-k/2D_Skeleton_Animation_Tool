#include "BindPoseGenerator/skeletonhierarchytreewidget.h"
#include "BindPoseGenerator/jointtreewidgetitem.h"
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "QKeyEvent"
#include "Skeleton.h"
#include <QDebug>

SkeletonHierarchyTreeWidget::SkeletonHierarchyTreeWidget(QWidget* parent)
    :QTreeWidget(parent),parent(static_cast<BindPoseAnimSampleGenerator*>(parent))
{
}

void SkeletonHierarchyTreeWidget::AddJoint(QSharedPointer<Joint> joint)
{
    JointTreeWidgetItem* item = new JointTreeWidgetItem(joint);
    addTopLevelItem(item);
}

void SkeletonHierarchyTreeWidget::RemoveJoint(Joint* joint)
{
    //since the flag has set Match Exactly...each joint name should be different.
    QTreeWidgetItem* jointItem = findItems(joint->name,Qt::MatchExactly|Qt::MatchRecursive)[0];
    //this is proven safe by the document.
    delete jointItem;
}

void SkeletonHierarchyTreeWidget::keyPressEvent(QKeyEvent *event)
{
    ushort key = event->text()[0].unicode();
    if(topLevelItemCount() == 0)
    {
        return;
    }
    JointTreeWidgetItem* item = static_cast<JointTreeWidgetItem*>(selectedItems()[0]);
    QString prevName = item->text(0);
    QString text = item->text(0);

    if(event->key() == Qt::Key_Delete)
    {
        parent->RemoveJoint(item->jointData);
        return;
    }
    else if(event->key() == Qt::Key_Backspace && text.size()> 0)
    {
        text.resize(text.size()-1);
    }
    else if((Qt::Key_0 <= key && key <= Qt::Key_9) ||
            (QChar('a').unicode() <= key && key <= QChar('z').unicode())||
            (QChar('A').unicode() <= key && key <= QChar('Z').unicode()) ||
             event->key() == Qt::Key_Underscore)
    {
        text.push_back(key);
    }
    item->setText(0,text);
    parent->SetJointName(*item->jointData.data(),text);
    item->jointData->name = text;
    QTreeWidget::keyPressEvent(event);
}

void SkeletonHierarchyTreeWidget::dropEvent(QDropEvent *event)
{
    qDebug()<<"drop";
    JointTreeWidgetItem* ItemUnderDrop = static_cast<JointTreeWidgetItem*>(itemAt(event->pos()));
    if(draggingItem == ItemUnderDrop || draggingItem == nullptr || ItemUnderDrop == nullptr)
        return;

    if(draggingItem->parent() != nullptr)
        draggingItem->parent()->removeChild(draggingItem);
    ItemUnderDrop->addChild(draggingItem);
    QTreeWidget::dropEvent(event);
}

void SkeletonHierarchyTreeWidget::mousePressEvent(QMouseEvent *event)
{
    draggingItem = static_cast<JointTreeWidgetItem*>(itemAt(event->pos()));
    QTreeWidget::mousePressEvent(event);
}

Skeleton SkeletonHierarchyTreeWidget::GetSkeletonInstance(QString fileName)
{
    Skeleton skeleton((fileName + "Skeleton"));
    //there must be a guarentee that there is only one topLevelItem and it is the root joint.
    JointTreeWidgetItem* rootJointItem = static_cast<JointTreeWidgetItem*>(topLevelItem(0));
    std::function<void(JointTreeWidgetItem*)> loadSkeleton = [loadSkeleton,&skeleton](JointTreeWidgetItem* jointItem)
    {
        //파라미터로 받은 조인트를 스켈레톤 조인트 벡터에 넣고 자식 조인트가 있으면 가져와서 loadSkeleton함수에 넘겨서 재귀로 호출해주고 없으면 리턴하는 로직.
        skeleton.AddJoint(*(jointItem->jointData));
        if(jointItem->childCount() == 0)
            return;
        for(int i = 0; i < jointItem->childCount(); i++)
        {
            JointTreeWidgetItem* childJoint = static_cast<JointTreeWidgetItem*>(jointItem->child(i));
            loadSkeleton(childJoint);
        }
    };
    return skeleton;
}
