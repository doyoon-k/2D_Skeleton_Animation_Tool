#include "Joint.h"
#include <QTextStream>

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
