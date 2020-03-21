#pragma once
#include "Vector3D.h"


    struct [[nodiscard]] Joint
	{
        Joint(int parentIndex, const Vector3D& pos, const char* joint_name);

		int parentIndex = -1; //-1 means it is the origin joint in the skeleton hierarchy
        Vector3D position = { 0.f,0.f,0.f };//relative to parent. For the root joint, object transform position is the parent.
		const char* name = nullptr;
	};
