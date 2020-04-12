#ifndef JOINTTREEWIDGETITEM_H
#define JOINTTREEWIDGETITEM_H
#include <QTreeWidgetItem>
#include "Joint.h"

class JointTreeWidgetItem : public QTreeWidgetItem
{
    friend class SkeletonHierarchyTreeWidget;
public:
    JointTreeWidgetItem(QSharedPointer<Joint> joint);
    JointTreeWidgetItem(QTreeWidgetItem* parent,Joint* joint);
    void onDropEvent(JointTreeWidgetItem *newParent);
private:
    QSharedPointer<Joint> jointData;
};
#endif // JOINTTREEWIDGETITEM_H
