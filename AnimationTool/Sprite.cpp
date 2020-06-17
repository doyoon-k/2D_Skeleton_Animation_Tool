#include "Sprite.h"
//#include <QTextStream>

bool Sprite::operator==(const Sprite &other)
{
    if(parentJoint == other.parentJoint && name == other.name && bottomLeftCoord == other.bottomLeftCoord &&
       (rotationOffset-other.rotationOffset)<std::numeric_limits<float>::epsilon() && image == other.image){
        return true;
    }
    return false;
}

//void SaveSprite(QTextStream& stream,Sprite& sprite)
//{
//    stream<<sprite.connectedJointIndex;
//    stream<<sprite.rotationOffset;
//    stream<<sprite.name;
//}

//void LoadSprite(QTextStream& stream,Sprite& sprite)
//{
//    stream>>sprite.connectedJointIndex;
//    stream>>sprite.rotationOffset;
//    stream>>sprite.name;
//}
