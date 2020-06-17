#pragma once
#include "Vector3D.h"
#include <QImage>
#include <QSharedPointer>

struct Joint;

struct [[nodiscard]] Sprite
{
    bool operator==(const Sprite& other);
    QSharedPointer<Joint> parentJoint;
    int connectedJointIndex;
    QString name;
    Vector3D bottomLeftCoord;//relative to Object Transform position.
    float rotationOffset;
    QImage image;
};


void SaveSprite(QTextStream& stream,Sprite& sprite);

void LoadSprite(QTextStream& stream,Sprite& sprite);
