#ifndef SKELETONHIERARCHYTREEWIDGET_H
#define SKELETONHIERARCHYTREEWIDGET_H

#include <QTreeWidget>

struct Joint;

class SkeletonHierarchyTreeWidget : public QTreeWidget
{
public:
    SkeletonHierarchyTreeWidget(QWidget* parent);
    void AddJoint(const Joint& joint);
};

#endif // SKELETONHIERARCHYTREEWIDGET_H
