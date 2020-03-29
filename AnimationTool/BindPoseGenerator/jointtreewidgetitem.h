#ifndef JOINTTREEWIDGETITEM_H
#define JOINTTREEWIDGETITEM_H
#include <QTreeWidgetItem>
#include "Joint.h"

class JointTreeWidgetItem : public QTreeWidgetItem
{
    friend class SkeletonHierarchyTreeWidget;
public:
    JointTreeWidgetItem(const Joint& joint);
    JointTreeWidgetItem(QTreeWidgetItem* parent, const Joint& joint);
private:
    Joint jointData;
};
#endif // JOINTTREEWIDGETITEM_H
