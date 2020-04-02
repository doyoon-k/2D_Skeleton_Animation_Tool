#pragma once
#include "Vector3D.h"
#include "QImage"
#include "Joint.h"


struct [[nodiscard]] Sprite
{
    bool operator==(const Sprite& other);
    Joint parentJoint;
    int connectedJointIndex;
    QString name;
    Vector3D bottomLeftCoord;//relative to Object Transform position.
    float rotationOffset;
    QImage* pImage;
};




