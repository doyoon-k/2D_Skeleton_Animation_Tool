#pragma once
#include "Vector3D.h"
#include <QString>

struct [[nodiscard]] Joint
{
    Joint(int parentIndex, const Vector3D& pos, QString joint_name);
    bool operator==(const Joint& other)const;

    int parentIndex = -1; //-1 means it is the origin joint in the skeleton hierarchy
    Vector3D position = { 0.f,0.f,0.f };//relative to parent. For the root joint, object transform position is the parent.
    QString name;
};

//void LoadJoint(QTextStream& stream,Joint& joint);

//void SaveJoint(QTextStream& stream,Joint& joint);
