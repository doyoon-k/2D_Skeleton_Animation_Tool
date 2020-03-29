#include <BindPoseGenerator/jointtreewidgetitem.h>

JointTreeWidgetItem::JointTreeWidgetItem(const Joint &joint)
    :QTreeWidgetItem ({joint.name},Qt::UserRole+1),jointData(joint)
{

}


JointTreeWidgetItem::JointTreeWidgetItem(QTreeWidgetItem* parent, const Joint& joint)
    :QTreeWidgetItem(parent,{joint.name}),jointData(joint)
{
}


//void JointTreeWidgetItem::onDropEvent(JointTreeWidgetItem *newParent)
//{

//}
