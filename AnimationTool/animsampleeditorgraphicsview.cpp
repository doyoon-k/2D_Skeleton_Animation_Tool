#include "animsampleeditorgraphicsview.h"
#include "Skeleton.h"
#include "jointgraphicsitem.h"
#include "SpriteMesh.h"
#include "spritegraphicsitem.h"
#include <QSharedPointer>
#include "AnimationSample.h"
#include <QMouseEvent>
#include <QDebug>

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
        spriteGraphicsItem->setAcceptedMouseButtons(false);
        spriteGraphicsItems.push_back(spriteGraphicsItem);
        scene->addItem(spriteGraphicsItem);
        QTransform transform;
        transform.scale(GetScalarWidthPixel(),GetScalarHeightPixel());
        spriteGraphicsItem->setTransform(transform);
    }
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
            qDebug()<<"j : "<<jointItem->pos()<<endl;
            qDebug()<<event->pos();
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
        jointItem->setPos(parentJointItem->pos().x() + parentToMouse[0],parentJointItem->pos().y() + parentToMouse[1]);

        std::function<void(int)> moveChildJointsBy = [&](int parentJointIndex)
        {
            for(int i = 0; i < skeletonIndexChildMap[parentJointIndex].size(); i++)
            {
                int childJointIndex = skeletonIndexChildMap[parentJointIndex][i];
                JointGraphicsItem* childJointItem = jointGraphicsItems[childJointIndex];
                const Joint& childJoint = *childJointItem->GetJoint();
                QPointF parentPos = jointGraphicsItems[parentJointIndex]->pos();
                qDebug()<<parentPos<<endl;
                qDebug()<<event->pos()<<endl;
                childJointItem->setPos(parentPos.x() + jointOffsetFromParent[childJointIndex][0],parentPos.y() + jointOffsetFromParent[childJointIndex][1]);
                moveChildJointsBy(childJointIndex);
            }
        };

        int currJointIndex = jointGraphicsItems.indexOf(jointItem);
        moveChildJointsBy(currJointIndex);
    }
    else if(SpriteGraphicsItem* spriteItem = dynamic_cast<SpriteGraphicsItem*>(currentSelectedItem); spriteItem != nullptr)
    {

    }
}

void AnimSampleEditorGraphicsView::Reset()
{
    BindPoseAnimSampleGeneratorGraphicsView::Reset();
    currentSelectedItem = nullptr;
    skeletonIndexChildMap.clear();
    jointOffsetFromParent.clear();
}

//AnimationSample AnimSampleEditorGraphicsView::GetAnimSample() const
//{

//}

