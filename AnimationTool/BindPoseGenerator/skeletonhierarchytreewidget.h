#ifndef SKELETONHIERARCHYTREEWIDGET_H
#define SKELETONHIERARCHYTREEWIDGET_H

#include <QTreeWidget>

struct Joint;
class BindPoseAnimSampleGenerator;

class SkeletonHierarchyTreeWidget : public QTreeWidget
{
      Q_OBJECT
public:
    SkeletonHierarchyTreeWidget(QWidget* parent);
    void AddJoint(const Joint& joint);
    void RemoveJoint(const Joint& joint);
    void keyPressEvent(QKeyEvent* event)override;
private:
    BindPoseAnimSampleGenerator* parent;
};

#endif // SKELETONHIERARCHYTREEWIDGET_H
