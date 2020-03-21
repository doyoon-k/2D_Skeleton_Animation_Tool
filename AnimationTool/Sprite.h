#pragma once
#include "Vector3D.h"
#include "QImage"

	struct [[nodiscard]] Sprite
	{
		int connectedJointIndex;
        Vector3D bottomLeftCoord;//relative to Object Transform position.
		float rotationOffset;
        QImage* pImage;
	};

