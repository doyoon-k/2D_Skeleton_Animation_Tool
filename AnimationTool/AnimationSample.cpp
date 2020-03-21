#include "AnimationSample.h"
#include "mathLib.h"

AnimationSample LerpAnimSample(const AnimationSample& sample1, const AnimationSample& sample2,float t)
{
	_ASSERT(strcmp(sample1.skeleton.GetName(), sample2.skeleton.GetName()) == 0 && strcmp(sample1.spriteMesh.name,sample2.name) == 0);
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
        const Vector3D& Sprite1ConnectedJointPos = sample1Skeleton.CalculateJointPosInSkeletonSpace(Sprite1.connectedJointIndex);

		const Sprite& Sprite2 = sample2SpriteMesh.sprites[i];

		float rotationOffset = lerp(Sprite1.rotationOffset, Sprite2.rotationOffset,t);
        Vector3D spriteLBottomCoordOffsetFromConnectedJoint = Matrix3X3::GetRotationMatrix(rotationOffset)*(Sprite1.bottomLeftCoord - Sprite1ConnectedJointPos);
		
		Sprite& newSprite = newSpriteMesh.sprites[i];
		newSprite.rotationOffset = rotationOffset;
		newSprite.bottomLeftCoord = newSkeleton.CalculateJointPosInSkeletonSpace(newSprite.connectedJointIndex) + spriteLBottomCoordOffsetFromConnectedJoint;
	}

	AnimationSample newAnimSample{ newSkeleton, newSpriteMesh , "lerpedAnimSample"};
	return newAnimSample;
}
