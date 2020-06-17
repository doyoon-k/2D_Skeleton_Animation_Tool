#pragma once
#ifndef BINDPOSEANIMSAMPLEGENERATOR_H
#define BINDPOSEANIMSAMPLEGENERATOR_H

#include <QWidget>
#include <QUndoStack>
#include <QFile>
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include "BindPoseGenerator/spritelistwidget.h"

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
    friend void BindPoseAnimSampleGeneratorGraphicsView::SignalAddSpriteToAnimSampleGeneratorWidget();
    friend void SpriteListWidget::keyPressEvent(QKeyEvent*);
public:
    explicit BindPoseAnimSampleGenerator(QWidget *parent = nullptr);
    void AddJoint(QSharedPointer<Joint> joint);
    void RemoveJoint(QSharedPointer<Joint> joint);
    void AddSprite(QSharedPointer<Sprite> sprite);
    void RemoveSprite(QSharedPointer<Sprite> sprite);

    void SetJointName(const Joint& joint,QString name);
    void SetSpriteName(const Sprite& sprite,QString name);

    void LoadBindPose(const QString& path);
    void SaveBindPose(const QString& path);

    void ConnectSpinboxSignals();
    BindPoseAnimSampleGeneratorGraphicsView* GetGraphicsView();
signals:

public slots:
private:
    void CreateActions();

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
