#include "animationclipeditorgraphicsview.h"
#include "animationclipeditor.h"
#include "jointgraphicsitem.h"
#include "spritegraphicsitem.h"
#include "AnimationSample.h"
#include "Joint.h"
#include <QDebug>
#include <QGraphicsScene>

AnimationClipEditorGraphicsView::AnimationClipEditorGraphicsView(QWidget* parent)
    :BindPoseAnimSampleGeneratorGraphicsView(parent),
     animationClipEditorWidget(static_cast<AnimationClipEditorWidget*>(parent))
{
}

void AnimationClipEditorGraphicsView::paintEvent(QPaintEvent *event)
{
    BindPoseAnimSampleGeneratorGraphicsView::paintEvent(event);
    if(!animationClipEditorWidget->IsPlaying())
        return;

    qreal currTime = timer.elapsed();
    animationClipEditorWidget->AddTime((currTime-prevTime)/1000.0);
    prevTime = currTime;
    const AnimationSample& animSample = animationClipEditorWidget->GetLerpedAnimSample();
    SetAnimationSample(animSample);
}

void AnimationClipEditorGraphicsView::SetAnimationSample(const AnimationSample &animSample)
{
    BindPoseAnimSampleGeneratorGraphicsView::Reset();
    Skeleton skeleton(animSample.skeleton);
    SpriteMesh spriteMesh(animSample.spriteMesh);
    for(int i = 0; i < skeleton.GetNumbertOfJoints(); i++)
    {
        Joint joint = skeleton.GetJoint(i);
        joint.position = skeleton.CalculateJointPosInSkeletonSpace(i);
        JointGraphicsItem* jointItem = new JointGraphicsItem(QSharedPointer<Joint>(new Joint(joint)),false);
        jointGraphicsItems.push_back(jointItem);
        scene->addItem(jointItem);
    }

    for(int i = 0; i < spriteMesh.nSprites; i++)
    {
        Sprite sprite = spriteMesh.sprites[i];
        SpriteGraphicsItem* spriteItem = new SpriteGraphicsItem(QSharedPointer<Sprite>(new Sprite(sprite)),false);
        spriteGraphicsItems.push_back(spriteItem);
        scene->addItem(spriteItem);
    }
    RescaleGraphicsItems();
}

void AnimationClipEditorGraphicsView::Reset()
{
    BindPoseAnimSampleGeneratorGraphicsView::Reset();
    timer.restart();
    prevTime = 0;
}
