#ifndef BINDPOSEANIMSAMPLEGENERATORGRAPHICSVIEW_H
#define BINDPOSEANIMSAMPLEGENERATORGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QPointF>

class QMenu;
class QActionGroup;
class BindPoseAnimSampleGenerator;
struct Joint;

class BindPoseAnimSampleGeneratorGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    BindPoseAnimSampleGeneratorGraphicsView(QWidget *parent = nullptr);
    void AddJoint(const Joint& joint);
protected:
    void mousePressEvent(QMouseEvent* event)override;
private:
    QMenu* jointCreateMenu;
    QAction* createJointAction;
    QGraphicsScene* scene;
    BindPoseAnimSampleGenerator* parent;
    QGraphicsEllipseItem* skeletonSpaceOrigin;

    void CreateActionMenu();
public slots:
    void AddJointSignalToParent();
};

#endif // BINDPOSEANIMSAMPLEGENERATORGRAPHICSVIEW_H
