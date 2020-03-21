#include "jointtreewidgetitem.h"

JointTreeWidgetItem::JointTreeWidgetItem(QTreeWidgetItem* parent, const Joint& joint)
    :QTreeWidgetItem(parent),jointData(joint)
{

}

//void JointTreeWidgetItem::onDropEvent(JointTreeWidgetItem *newParent)
//{

//}
