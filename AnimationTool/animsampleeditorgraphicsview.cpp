#include "animsampleeditorgraphicsview.h"
#include "Skeleton.h"
#include "jointgraphicsitem.h"
#include "SpriteMesh.h"
#include "spritegraphicsitem.h"
#include <QSharedPointer>
#include "AnimationSample.h"
#include <QMouseEvent>
#include <QDebug>
#include "mathLib.h"
#include <QtMath>

AnimSampleEditorGraphicsView::AnimSampleEditorGraphicsView(QWidget* parent)
    :BindPoseAnimSampleGeneratorGraphicsView(parent)
{
}

void AnimSampleEditorGraphicsView::LoadAnimSample(const Skeleton &skeleton, const SpriteMesh &spriteMesh)
{
    for(int i = 0; i < skeleton.GetNumbertOfJoints(); i++)
    {
        Joint joint = skeleton.GetJoint(i);
        if(joint.parentIndex != -1)
        {
            skeletonIndexChildMap[joint.parentIndex].push_back(i);
        }
        Vector3D offset = joint.position;
        offset[0] *= GetScalarWidthPixel();
        offset[1] *= GetScalarHeightPixel();
        jointOffsetFromParent.push_back(offset);
        joint.position = skeleton.CalculateJointPosInSkeletonSpace(i);
        joint.position[0] *= GetScalarWidthPixel();
        joint.position[1] *= GetScalarHeightPixel();
        JointGraphicsItem* jointItem = new JointGraphicsItem(QSharedPointer<Joint>(new Joint(joint)),false);
        jointItem->setAcceptDrops(false);
        jointItem->setAcceptedMouseButtons(false);
        jointGraphicsItems.push_back(jointItem);
        scene->addItem(jointItem);
    }

    for(int i = 0; i < spriteMesh.nSprites; i++)
    {
        Sprite sprite = spriteMesh.sprites[i];
        sprite.bottomLeftCoord[0] *= GetScalarWidthPixel();
        sprite.bottomLeftCoord[1] *= GetScalarHeightPixel();
        Vector3D offset = sprite.bottomLeftCoord - jointGraphicsItems[sprite.connectedJointIndex]->GetJoint()->position;
        spriteOffsetFromJoint.push_back(offset);
        sprite.parentJoint = GetJointGraphicsItemByName(skeleton.GetJoint(sprite.connectedJointIndex).name)->GetJoint();
        SpriteGraphicsItem* spriteGraphicsItem = new SpriteGraphicsItem(QSharedPointer<Sprite>(new Sprite(sprite)),false);
        spriteGraphicsItem->setAcceptDrops(false);
        spriteGraphicsItem->setAcceptedMouseButtons(false);
        spriteGraphicsItems.push_back(spriteGraphicsItem);
        scene->addItem(spriteGraphicsItem);
    }
    initialSpriteOffsetFromJoint = spriteOffsetFromJoint;
    RescaleGraphicsItems();
}

AnimationSample AnimSampleEditorGraphicsView::GetAnimSample(QString animSampleName)
{
    Skeleton skeleton(animSampleName+"Skeleton");
    skeleton.mNJoints = jointGraphicsItems.size();
    for(int i = 0; i < jointGraphicsItems.size(); i++)
    {
        Vector3D jointPos;
        jointPos[0] = jointOffsetFromParent[i][0] / GetScalarWidthPixel();
        jointPos[1] = jointOffsetFromParent[i][1] / GetScalarHeightPixel();
        Joint joint = *jointGraphicsItems[i]->GetJoint();
        joint.position = jointPos;
        skeleton.mJoints.push_back(joint);
    }

    SpriteMesh spriteMesh;
    spriteMesh.name = animSampleName+"SpriteMesh";
    spriteMesh.nSprites = spriteGraphicsItems.size();
    for(int i = 0; i < spriteGraphicsItems.size(); i++)
    {
        Sprite sprite = *spriteGraphicsItems[i]->GetSprite();
        Vector3D spritePos;
        spritePos[0] = sprite.bottomLeftCoord[0] / GetScalarWidthPixel();
        spritePos[1] = sprite.bottomLeftCoord[1] / GetScalarHeightPixel();
        sprite.bottomLeftCoord = spritePos;
        spriteMesh.sprites.push_back(sprite);
    }

    AnimationSample animSample{animSampleName,skeleton,spriteMesh};
    return animSample;
}

void AnimSampleEditorGraphicsView::mousePressEvent(QMouseEvent *event)
{
    currentSelectedItem = itemAt(event->pos());
}

void AnimSampleEditorGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    currentSelectedItem = nullptr;
}

void AnimSampleEditorGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    //조인트아이템이면 ~~
    if(JointGraphicsItem* jointItem = dynamic_cast<JointGraphicsItem*>(currentSelectedItem); jointItem != nullptr)
    {
        if(jointItem->GetJoint()->parentIndex == -1)
        {
            return;
        }

        JointGraphicsItem* parentJointItem = jointGraphicsItems[jointItem->GetJoint()->parentIndex];
        QPointF mousePos = event->pos();
        mousePos.setY(scene->height()-mousePos.y());
        QPointF diffParentMouse = mousePos - parentJointItem->pos();
        Vector3D parentToMouse(diffParentMouse.x(),diffParentMouse.y());
        parentToMouse.Normalize();

        QPointF diffParentCurrent = jointItem->pos()-parentJointItem->pos();
        float parentCurrentJointDistance = Vector3D(diffParentCurrent.x(),diffParentCurrent.y()).GetLength();
        parentToMouse *= parentCurrentJointDistance;

        jointItem->GetJoint()->position = parentJointItem->GetJoint()->position + parentToMouse;
        int index = jointGraphicsItems.indexOf(jointItem);
        jointOffsetFromParent[index] = parentToMouse;
        jointItem->setPos(parentJointItem->pos().x() + parentToMouse[0],parentJointItem->pos().y() + parentToMouse[1]);

        std::function<void(int)> moveChildJointsBy = [&](int parentJointIndex)
        {
            for(int i = 0; i < skeletonIndexChildMap[parentJointIndex].size(); i++)
            {
                int childJointIndex = skeletonIndexChildMap[parentJointIndex][i];
                JointGraphicsItem* childJointItem = jointGraphicsItems[childJointIndex];
                const Joint& childJoint = *childJointItem->GetJoint();
                QPointF parentPos = jointGraphicsItems[parentJointIndex]->pos();
                childJointItem->setPos(parentPos.x() + jointOffsetFromParent[childJointIndex][0],parentPos.y() + jointOffsetFromParent[childJointIndex][1]);

                moveChildJointsBy(childJointIndex);
            }
        };

        int currJointIndex = jointGraphicsItems.indexOf(jointItem);
        moveChildJointsBy(currJointIndex);

        for(int i = 0; i < spriteGraphicsItems.size(); i++)
        {
            SpriteGraphicsItem* item = spriteGraphicsItems[i];
            QPointF offset(spriteOffsetFromJoint[i][0],spriteOffsetFromJoint[i][1]);
            QPointF connectedJointPos = jointGraphicsItems[item->GetSprite()->connectedJointIndex]->pos();
            item->setPos(connectedJointPos + offset);
            item->GetSprite()->bottomLeftCoord = Vector3D(connectedJointPos.x(),connectedJointPos.y()) + spriteOffsetFromJoint[i];
        }
    }
    else if(SpriteGraphicsItem* spriteItem = dynamic_cast<SpriteGraphicsItem*>(currentSelectedItem); spriteItem != nullptr)
    {
        int spriteItemIndex = spriteGraphicsItems.indexOf(spriteItem);
        Vector3D offset = spriteOffsetFromJoint[spriteItemIndex];
        float spriteJointOffsetDistance = offset.GetLength();
        QPointF mousePos = event->pos();
        mousePos.setY(scene->height() - mousePos.y());

        QPointF diffJointMouse = mousePos - jointGraphicsItems[spriteItem->GetSprite()->connectedJointIndex]->pos();
        Vector3D jointToMouse(diffJointMouse.x(),diffJointMouse.y());
        jointToMouse.Normalize();
        jointToMouse *= spriteJointOffsetDistance;

        //원래 오프셋벡터와 조인트 투 마우스 벡터의 각도를 계산, spriteItem의 rotationOffset을 더해줌.
        float rotationOffset = GetRadOffset(offset,jointToMouse);
        spriteItem->GetSprite()->rotationOffset += rotationOffset;
        spriteItem->GetSprite()->rotationOffset = std::fmod(spriteItem->GetSprite()->rotationOffset,6.283185f);

        spriteOffsetFromJoint[spriteItemIndex] = jointToMouse;

        QPointF jointPos = jointGraphicsItems[spriteItem->GetSprite()->connectedJointIndex]->pos();
        spriteItem->setPos(jointPos.x() + jointToMouse[0],jointPos.y() + jointToMouse[1]);
        spriteItem->GetSprite()->bottomLeftCoord = Vector3D(jointPos.x() + jointToMouse[0],jointPos.y() + jointToMouse[1]);
    }
}

void AnimSampleEditorGraphicsView::Reset()
{
    BindPoseAnimSampleGeneratorGraphicsView::Reset();
    currentSelectedItem = nullptr;
    skeletonIndexChildMap.clear();
    jointOffsetFromParent.clear();
    spriteOffsetFromJoint.clear();
    initialSpriteOffsetFromJoint.clear();
}
