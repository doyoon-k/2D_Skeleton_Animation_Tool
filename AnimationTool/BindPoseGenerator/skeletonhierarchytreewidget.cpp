#include "BindPoseGenerator/skeletonhierarchytreewidget.h"
#include "BindPoseGenerator/jointtreewidgetitem.h"
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "QKeyEvent"
#include "Skeleton.h"
#include "jointgraphicsitem.h"
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
    JointTreeWidgetItem* item = static_cast<JointTreeWidgetItem*>(currentItem());
    qDebug()<<item->text(0);
    if(item == nullptr)
        return;
    QString prevName = item->text(0);
    QString text = item->text(0);

    if(event->key() == Qt::Key_Delete)
    {
        //자식노드의 조인트데이타까지 재귀적으로 호출
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
}

void SkeletonHierarchyTreeWidget::dropEvent(QDropEvent *event)
{
    QTreeWidget::dropEvent(event);
}

void SkeletonHierarchyTreeWidget::mousePressEvent(QMouseEvent *event)
{
    draggingItem = static_cast<JointTreeWidgetItem*>(itemAt(event->pos()));
    QTreeWidget::mousePressEvent(event);
}

Skeleton SkeletonHierarchyTreeWidget::GetSkeletonInstance(QString poseName)
{
    Skeleton skeleton((poseName + "Skeleton"));
    int nJoints = 0;
    //there must be a guarentee that there is only one topLevelItem and it is the root joint.
    JointTreeWidgetItem* rootJointItem = static_cast<JointTreeWidgetItem*>(topLevelItem(0));
    std::function<void(JointTreeWidgetItem*,int)> loadSkeleton = [&loadSkeleton,&skeleton,&nJoints,this](JointTreeWidgetItem* jointItem,int parentIndex)
    {
        //파라미터로 받은 조인트를 스켈레톤 조인트 벡터에 넣고 자식 조인트가 있으면 가져와서 loadSkeleton함수에 넘겨서 재귀로 호출해주고 없으면 리턴하는 로직.
        jointItem->jointData->parentIndex = parentIndex;
        if(parentIndex != -1)
        {
            JointGraphicsItem* parentJointItem = parent->GetGraphicsView()->GetJointGraphicsItemByName(skeleton.mJoints[parentIndex].name);
            jointItem->jointData->position -= parentJointItem->GetJoint()->position;
        }
        jointItem->jointData->position[0] /= parent->GetGraphicsView()->GetScalarWidthPixel();
        jointItem->jointData->position[1] /= parent->GetGraphicsView()->GetScalarHeightPixel();
        skeleton.AddJoint(*(jointItem->jointData));
        nJoints++;
        int currIndex = nJoints;
        if(jointItem->childCount() == 0)
            return;
        for(int i = 0; i < jointItem->childCount(); i++)
        {
            JointTreeWidgetItem* childJoint = static_cast<JointTreeWidgetItem*>(jointItem->child(i));
            childJoint->jointData->parentIndex = parentIndex;
            loadSkeleton(childJoint,currIndex - 1);
        }
    };
    loadSkeleton(rootJointItem,-1);
    skeleton.mNJoints = nJoints;
    return skeleton;
}

void SkeletonHierarchyTreeWidget::LoadFromSkeleton(const Skeleton &skeleton)
{
    for(int i = 0; i < skeleton.mNJoints; i++)
    {
        parent->AddJoint(QSharedPointer<Joint>(new Joint(skeleton.mJoints[i])));
    }

    for(int i = skeleton.mNJoints - 1; i > 0; i--)
    {
         QTreeWidgetItem* jointItem = findItems(skeleton.mJoints[i].name,Qt::MatchExactly|Qt::MatchRecursive)[0];
         QTreeWidgetItem* parentItem = findItems(skeleton.mJoints[skeleton.mJoints[i].parentIndex].name,Qt::MatchExactly|Qt::MatchRecursive)[0];
         parentItem->addChild(jointItem);
    }
}
