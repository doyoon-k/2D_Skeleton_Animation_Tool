#ifndef SKELETONHIERARCHYTREEWIDGET_H
#define SKELETONHIERARCHYTREEWIDGET_H

#include <QTreeWidget>

struct Joint;
class BindPoseAnimSampleGenerator;
class JointTreeWidgetItem;
class Skeleton;

class SkeletonHierarchyTreeWidget : public QTreeWidget
{
      Q_OBJECT
public:
    SkeletonHierarchyTreeWidget(QWidget* parent);
    void AddJoint(QSharedPointer<Joint> joint);
    void RemoveJoint(Joint* joint);
    void keyPressEvent(QKeyEvent* event) override;
    void dropEvent(QDropEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    Skeleton GetSkeletonInstance(QString poseName);
    void LoadFromSkeleton(Skeleton& skeleton);
    void Reset();
private:
    BindPoseAnimSampleGenerator* parent;
    JointTreeWidgetItem* draggingItem = nullptr;
};

#endif // SKELETONHIERARCHYTREEWIDGET_H
