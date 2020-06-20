#include "Skeleton.h"
#include <QTextStream>

Skeleton::Skeleton(QString name)
	:mName(name)
{
}

QString Skeleton::GetName() const
{
	return mName;
}

int Skeleton::GetJointByName(Joint& dstJoint, const char* jointName)
{
    for(int i = 0; i < mJoints.size(); i++)
    {
        if (mJoints[i].name == QString(jointName))
        {
            dstJoint = mJoints[i];
            return i;
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

void Skeleton::AddJoint(Joint newJoint)
{
    mJoints.push_back(newJoint);
}

int Skeleton::GetJointIndexByName(QString jointName)
{
    for(int i = 0; i < mJoints.size(); i++)
    {
        if (mJoints[i].name == QString(jointName))
        {
            return i;
        }
    }

    return -1;
}

void LoadSkeleton(QTextStream& stream,Skeleton& skeleton)
{
    stream>>skeleton.mNJoints;
    stream>>skeleton.mName;
    skeleton.mJoints.reserve(skeleton.mNJoints);
    for(int i = 0; i < skeleton.mNJoints; i++)
    {
        LoadJoint(stream,skeleton.mJoints[i]);
    }
}


void SaveSkeleton(QTextStream& stream,Skeleton& skeleton)
{
    stream<<skeleton.mNJoints<<endl;
    stream<<skeleton.mName<<endl;
    for(int i = 0; i < skeleton.mNJoints; i++)
    {
        SaveJoint(stream,skeleton.mJoints[i]);
    }
}
