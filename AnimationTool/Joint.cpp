#include "Joint.h"
#include <QTextStream>

Joint::Joint(int parentIndex, const Vector3D& pos, QString joint_name)
	:parentIndex(parentIndex),position(pos),name(joint_name)
{
}

bool Joint::operator==(const Joint &other)const
{
    return(name == other.name && position == other.position);
}

void LoadJoint(QTextStream& stream,Joint& joint)
{
    stream>>joint.parentIndex;
    stream>>joint.position;
    stream>>joint.name;
}


void SaveJoint(QTextStream& stream,Joint& joint)
{
    stream<<joint.parentIndex<<endl;
    stream<<joint.position<<endl;
    stream<<joint.name<<endl;
}
