#pragma once
#include "Skeleton.h"
#include "SpriteMesh.h"


	struct [[nodiscard]] AnimationSample
	{
		Skeleton skeleton;
		SpriteMesh spriteMesh;
		const char* name;
	};

	AnimationSample LerpAnimSample(const AnimationSample& sample1, const AnimationSample& sample2,float t);
