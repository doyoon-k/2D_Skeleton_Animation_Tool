#ifndef BINDPOSEANIMSAMPLEGENERATOR_H
#define BINDPOSEANIMSAMPLEGENERATOR_H

#include <QWidget>
#include <QUndoStack>

class BindPoseAnimSampleGeneratorGraphicsView;
class QGraphicsScene;
class SpriteListWidget;
class SkeletonHierarchyTreeWidget;
struct Joint;

class BindPoseAnimSampleGenerator : public QWidget
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit BindPoseAnimSampleGenerator(QWidget *parent = nullptr);
    void AddJoint(const Joint& joint);
signals:

public slots:

private:
    void CreateActions();

    BindPoseAnimSampleGeneratorGraphicsView* graphicsView;
    SpriteListWidget* spriteListWidget;
    SkeletonHierarchyTreeWidget* skeleonHierarchyTreeWidget;
    QAction* undoAction;
    QAction* redoAction;
    QUndoStack* undoStack;
};

#endif // BINDPOSEANIMSAMPLEGENERATOR_H
