#pragma once
#include <vector>
#include "Joint.h"


	class [[nodiscard]] Skeleton
	{
		friend class SkeletonComponent;
	public:
		Skeleton(const char* name);
		const char* GetName() const;
		int GetJointByName(Joint& dstJoint,const char* jointName);//returns 1 if matching joint was found. if not, returns 0
		int GetNumbertOfJoints()const;
		Joint& GetJoint(int index);
		Joint GetJoint(int index)const;

		//the origin is the object's transform position
        Vector3D CalculateJointPosInSkeletonSpace(int jointIndex);
        Vector3D CalculateJointPosInSkeletonSpace(int jointIndex) const;
	private:
		int mNJoints = 0;
		const char* mName;
		std::vector<Joint> mJoints;
	};

