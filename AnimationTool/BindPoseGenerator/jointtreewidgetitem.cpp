#include <BindPoseGenerator/jointtreewidgetitem.h>

JointTreeWidgetItem::JointTreeWidgetItem(QSharedPointer<Joint> joint)
    :QTreeWidgetItem ({joint->name},Qt::UserRole+1),jointData(joint)
{

}


JointTreeWidgetItem::JointTreeWidgetItem(QTreeWidgetItem* parent, Joint* joint)
    :QTreeWidgetItem(parent,{joint->name}),jointData(joint)
{
}

JointTreeWidgetItem::JointTreeWidgetItem(const JointTreeWidgetItem &other)
    :QTreeWidgetItem(other),jointData(other.jointData)
{
    //idk why but you have to delete original item to add it to other item as child.
    int otherChildCount = other.childCount();
    for(int i = 0; i < otherChildCount; i++)
    {
        JointTreeWidgetItem* otherChild = new JointTreeWidgetItem(*static_cast<JointTreeWidgetItem*>(other.child(0)));
        delete other.child(0);
        addChild(otherChild);
    }
}


void JointTreeWidgetItem::onDropEvent(JointTreeWidgetItem *newParent)
{

}
