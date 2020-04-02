#ifndef BINDPOSEANIMSAMPLEGENERATOR_H
#define BINDPOSEANIMSAMPLEGENERATOR_H

#include <QWidget>
#include <QUndoStack>

class BindPoseAnimSampleGeneratorGraphicsView;
class QGraphicsScene;
class SpriteListWidget;
class SkeletonHierarchyTreeWidget;
class QSpinBox;
struct Joint;
struct Sprite;

class BindPoseAnimSampleGenerator : public QWidget
{
    Q_OBJECT
    friend class MainWindow;
    friend class AddJointCommand;
    friend class AddSpriteCommand;
public:
    explicit BindPoseAnimSampleGenerator(QWidget *parent = nullptr);
    void AddJoint(const Joint& joint);
    void RemoveJoint(const Joint& joint);
    void AddSprite(const Sprite& sprite);
    void RemoveSprite(const Sprite& sprite);

    void SetJointName(const Joint& joint,QString name);
    void SetSpriteName(const Sprite& sprite,QString name);

    void ConnectSpinboxSignals();
signals:

public slots:
    void Test();
private:
    void CreateActions();
    void OnRemoveJoint(const Joint& joint);

    BindPoseAnimSampleGeneratorGraphicsView* graphicsView;
    SpriteListWidget* spriteListWidget;
    SkeletonHierarchyTreeWidget* skeleonHierarchyTreeWidget;
    QSpinBox* widthPixelSpinBox;
    QSpinBox* heightPixelSpinBox;
    QAction* undoAction;
    QAction* redoAction;
    QUndoStack* undoStack;
};

#endif // BINDPOSEANIMSAMPLEGENERATOR_H
