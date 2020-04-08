#include "Sprite.h"

bool Sprite::operator==(const Sprite &other)
{
    if(parentJoint == other.parentJoint && name == other.name && bottomLeftCoord == other.bottomLeftCoord &&
       (rotationOffset-other.rotationOffset)<std::numeric_limits<float>::epsilon() && image == other.image){
        return true;
    }
    return false;
}
