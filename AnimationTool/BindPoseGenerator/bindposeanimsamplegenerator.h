#ifndef BINDPOSEANIMSAMPLEGENERATOR_H
#define BINDPOSEANIMSAMPLEGENERATOR_H

#include <QWidget>
#include <QUndoStack>
#include <QFile>
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"

class BindPoseAnimSampleGeneratorGraphicsView;
class QGraphicsScene;
class SpriteListWidget;
class SkeletonHierarchyTreeWidget;
class QSpinBox;
struct Joint;
struct Sprite;
class QListWidget;

class BindPoseAnimSampleGenerator : public QWidget
{
    Q_OBJECT
    friend class MainWindow;
    friend class AddJointCommand;
    friend class AddSpriteCommand;
    friend void BindPoseAnimSampleGeneratorGraphicsView::SignalAddSpriteToAnimSampleGeneratorWidget();
public:
    explicit BindPoseAnimSampleGenerator(QWidget *parent = nullptr);
    void AddJoint(const Joint& joint);
    void RemoveJoint(const Joint& joint);
    void AddSprite(const Sprite& sprite);
    void RemoveSprite(const Sprite& sprite);

    void SetJointName(const Joint& joint,QString name);
    void SetSpriteName(const Sprite& sprite,QString name);

    void ConnectSpinboxSignals();
    void LoadImagePath(QString path);
signals:

public slots:
private:
    void CreateActions();
    void OnRemoveJoint(const Joint& joint);

    BindPoseAnimSampleGeneratorGraphicsView* graphicsView;
    SpriteListWidget* spriteListWidget;
    SkeletonHierarchyTreeWidget* skeleonHierarchyTreeWidget;
    QListWidget* imagesListWidget;
    QSpinBox* widthPixelSpinBox;
    QSpinBox* heightPixelSpinBox;
    QAction* undoAction;
    QAction* redoAction;
    QUndoStack* undoStack;

//    QVector<QString> imagesPath;
};

#endif // BINDPOSEANIMSAMPLEGENERATOR_H
