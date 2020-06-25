#include "AnimationSample.h"
#include "mathLib.h"
#include <QTextStream>

AnimationSample LerpAnimSample(const AnimationSample& sample1, const AnimationSample& sample2,float t)
{
    _ASSERT(sample1.skeleton.GetNumbertOfJoints() == sample2.skeleton.GetNumbertOfJoints() && sample1.spriteMesh.nSprites == sample2.spriteMesh.nSprites);
	Skeleton newSkeleton = sample1.skeleton;
    const Skeleton& sample1Skeleton = sample1.skeleton;
    const Skeleton& sample2Skeleton = sample2.skeleton;

	SpriteMesh newSpriteMesh = sample1.spriteMesh;
    const SpriteMesh& sample1SpriteMesh = sample1.spriteMesh;
    const SpriteMesh& sample2SpriteMesh = sample2.spriteMesh;

	int n_Joints = newSkeleton.GetNumbertOfJoints();

	for (int i = 0; i < n_Joints; i++)
	{
        Joint& newJoint = newSkeleton.GetJoint(i);
        Vector3D sample1JointPos = sample1Skeleton.GetJoint(i).position;
        Vector3D sample2JointPos = sample2Skeleton.GetJoint(i).position;

		newJoint.position = slerp(sample1JointPos, sample2JointPos, t);
	}

	int nSprites = newSpriteMesh.nSprites;
	for (int i = 0; i < nSprites; i++)
    {
        const Sprite& Sprite1 = sample1SpriteMesh.sprites[i];
        const Sprite& Sprite2 = sample2SpriteMesh.sprites[i];

        float rotationOffset = lerp(Sprite1.rotationOffset, Sprite2.rotationOffset,t);

        Vector3D sprite1OffsetFromJoint = Sprite1.bottomLeftCoord - sample1Skeleton.CalculateJointPosInSkeletonSpace(Sprite1.connectedJointIndex);
        Vector3D sprite2OffsetFromJoint = Sprite2.bottomLeftCoord - sample2Skeleton.CalculateJointPosInSkeletonSpace(Sprite2.connectedJointIndex);

        Vector3D newSpriteOffsetFromJoint = slerp(sprite1OffsetFromJoint,sprite2OffsetFromJoint,t);

		Sprite& newSprite = newSpriteMesh.sprites[i];
        newSprite.rotationOffset = rotationOffset;
        newSprite.bottomLeftCoord = newSkeleton.CalculateJointPosInSkeletonSpace(newSprite.connectedJointIndex) + newSpriteOffsetFromJoint;
	}

    AnimationSample newAnimSample{ "lerpedAnimSample",newSkeleton, newSpriteMesh};
	return newAnimSample;
}

void LoadAnimSample(QTextStream& stream,AnimationSample& animSample)
{
    stream>>animSample.name;
    LoadSkeleton(stream,animSample.skeleton);
    LoadSpriteMesh(stream,animSample.spriteMesh);
}


void SaveAnimSample(QTextStream& stream,AnimationSample& animSample)
{
    stream<<animSample.name<<endl;
    SaveSkeleton(stream,animSample.skeleton);
    SaveSpriteMesh(stream,animSample.spriteMesh);
}
