#include "skeletonhierarchytreewidget.h"
#include "jointtreewidgetitem.h"

SkeletonHierarchyTreeWidget::SkeletonHierarchyTreeWidget(QWidget* parent)
    :QTreeWidget(parent)
{
}

void SkeletonHierarchyTreeWidget::AddJoint(const Joint &joint)
{
    addTopLevelItem(new JointTreeWidgetItem(nullptr,joint));
}
