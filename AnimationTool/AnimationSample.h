#pragma once
#include "Skeleton.h"
#include "SpriteMesh.h"


	struct [[nodiscard]] AnimationSample
	{
        QString name;
		Skeleton skeleton;
		SpriteMesh spriteMesh;
	};

	AnimationSample LerpAnimSample(const AnimationSample& sample1, const AnimationSample& sample2,float t);

    void LoadAnimSample(QTextStream& stream,AnimationSample& animSample);

    void SaveAnimSample(QTextStream& stream,AnimationSample& animSample);

