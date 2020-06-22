#include "animsampleeditorgraphicsview.h"
#include "Skeleton.h"
#include "jointgraphicsitem.h"
#include "SpriteMesh.h"
#include "spritegraphicsitem.h"
#include <QSharedPointer>
#include "AnimationSample.h"

AnimSampleEditorGraphicsView::AnimSampleEditorGraphicsView(QWidget* parent)
    :BindPoseAnimSampleGeneratorGraphicsView(parent)
{
}

void AnimSampleEditorGraphicsView::LoadAnimSample(const Skeleton &skeleton, const SpriteMesh &spriteMesh)
{
    for(int i = 0; i < skeleton.GetNumbertOfJoints(); i++)
    {
        Joint joint = skeleton.GetJoint(i);
        joint.position = skeleton.CalculateJointPosInSkeletonSpace(i);
        joint.position[0] *= GetScalarWidthPixel();
        joint.position[1] *= GetScalarHeightPixel();
        JointGraphicsItem* jointItem = new JointGraphicsItem(QSharedPointer<Joint>(new Joint(joint)),false);
        jointItem->setAcceptDrops(false);
        jointGraphicsItems.push_back(jointItem);
        scene->addItem(jointItem);
        update();
    }

    for(int i = 0; i < spriteMesh.nSprites; i++)
    {
        Sprite sprite = spriteMesh.sprites[i];
        sprite.bottomLeftCoord[0] *= GetScalarWidthPixel();
        sprite.bottomLeftCoord[1] *= GetScalarHeightPixel();
        sprite.parentJoint = GetJointGraphicsItemByName(skeleton.GetJoint(sprite.connectedJointIndex).name)->GetJoint();
        SpriteGraphicsItem* spriteGraphicsItem = new SpriteGraphicsItem(QSharedPointer<Sprite>(new Sprite(sprite)),false);
        spriteGraphicsItem->setAcceptDrops(false);
        spriteGraphicsItems.push_back(spriteGraphicsItem);
        scene->addItem(spriteGraphicsItem);
        QTransform transform;
        transform.scale(GetScalarWidthPixel(),GetScalarHeightPixel());
        spriteGraphicsItem->setTransform(transform);
    }
}

//AnimationSample AnimSampleEditorGraphicsView::GetAnimSample() const
//{

//}

