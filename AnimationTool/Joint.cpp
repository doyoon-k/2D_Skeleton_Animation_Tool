#include "Joint.h"

Joint::Joint(int parentIndex, const Vector3D& pos, const char* joint_name)
	:parentIndex(parentIndex),position(pos),name(joint_name)
{
}
