#include "Sprite.h"
#include "mainwindow.h"
#include <QTextStream>

bool Sprite::operator==(const Sprite &other)
{
    if(parentJoint == other.parentJoint && name == other.name && bottomLeftCoord == other.bottomLeftCoord &&
       (rotationOffset-other.rotationOffset)<std::numeric_limits<float>::epsilon() && image == other.image){
        return true;
    }
    return false;
}

void SaveSprite(QTextStream& stream,Sprite& sprite)
{
    stream<<sprite.connectedJointIndex<<endl;
    stream<<sprite.name<<endl;
    stream<<sprite.bottomLeftCoord<<endl;
    stream<<sprite.rotationOffset<<endl;
}

void LoadSprite(QTextStream& stream,Sprite& sprite)
{
    stream>>sprite.connectedJointIndex;
    stream>>sprite.name;
    stream>>sprite.bottomLeftCoord;
    stream>>sprite.rotationOffset;
    sprite.image = QImage(MainWindow::GetImagePathBySpriteName(sprite.name));
}
