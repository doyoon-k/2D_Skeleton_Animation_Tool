#ifndef BINDPOSEANIMSAMPLEGENERATOR_H
#define BINDPOSEANIMSAMPLEGENERATOR_H

#include <QWidget>

class BindPoseAnimSampleGeneratorGraphicsView;
class QGraphicsScene;
class SpriteListWidget;
class SkeletonHierarchyTreeWidget;

class BindPoseAnimSampleGenerator : public QWidget
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit BindPoseAnimSampleGenerator(QWidget *parent = nullptr);
    void test(){}
signals:

public slots:
private:
    BindPoseAnimSampleGeneratorGraphicsView* graphicsView;
    QGraphicsScene* graphicsScene;
    SpriteListWidget* spriteListWidget;
    SkeletonHierarchyTreeWidget* skeleonHierarchyTreeWidget;
};

#endif // BINDPOSEANIMSAMPLEGENERATOR_H
