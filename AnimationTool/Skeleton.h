#pragma once
#include <vector>
#include "Joint.h"

    class SkeletonHierarchyTreeWidget;
	class [[nodiscard]] Skeleton
	{
		friend class SkeletonComponent;
        friend class SkeletonHierarchyTreeWidget;
        friend class AnimSampleEditorGraphicsView;
        friend void LoadSkeleton(QTextStream& stream,Skeleton& skeleton);
        friend void SaveSkeleton(QTextStream& stream,Skeleton& skeleton);
	public:
        Skeleton(QString name);
        QString GetName() const;
        int GetJointByName(Joint& dstJoint,const char* jointName);//returns index of the joint if matching joint was found. if not, returns 0
        int GetJointIndexByName(QString jointName);//returns index of the joint if matching joint was found. if not, returns -1
		int GetNumbertOfJoints()const;
		Joint& GetJoint(int index);
		Joint GetJoint(int index)const;
        void AddJoint(Joint newJoint);

		//the origin is the object's transform position
        Vector3D CalculateJointPosInSkeletonSpace(int jointIndex) const;
	private:
		int mNJoints = 0;
        QString mName;
		std::vector<Joint> mJoints;
	};

    void LoadSkeleton(QTextStream& stream,Skeleton& skeleton);

    void SaveSkeleton(QTextStream& stream,Skeleton& skeleton);
