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
    JointTreeWidgetItem(const JointTreeWidgetItem& other);
private:
    QSharedPointer<Joint> jointData;
};
#endif // JOINTTREEWIDGETITEM_H
