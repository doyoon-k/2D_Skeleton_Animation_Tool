#include "Skeleton.h"

Skeleton::Skeleton(const char* name)
	:mName(name)
{
}

const char* Skeleton::GetName() const
{
	return mName;
}

int Skeleton::GetJointByName(Joint& dstJoint, const char* jointName)
{
	for (Joint& joint : mJoints)
	{
        if (joint.name == QString(jointName))
		{
			dstJoint = joint;
			return 1;
		}
	}
	
	return 0;
}

int Skeleton::GetNumbertOfJoints() const
{
	return mNJoints;
}

Joint& Skeleton::GetJoint(int index)
{
	return mJoints[index];
}

Joint Skeleton::GetJoint(int index) const
{
	return mJoints[index];
}

Vector3D Skeleton::CalculateJointPosInSkeletonSpace(int jointIndex)
{
	Joint& joint = mJoints[jointIndex];
    Vector3D position = joint.position;

	while (joint.parentIndex != -1)
	{
		joint = mJoints[joint.parentIndex];
		position += joint.position;
	}
    position += mJoints[0].position;

	return position;
}

Vector3D Skeleton::CalculateJointPosInSkeletonSpace(int jointIndex) const
{
	Joint joint = mJoints[jointIndex];
    Vector3D position = joint.position;

	while (joint.parentIndex != -1)
	{
		joint = mJoints[joint.parentIndex];
		position += joint.position;
	}
	position += mJoints[0].position;

	return position;
}
