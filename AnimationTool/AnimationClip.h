#pragma once
#include "AnimationSample.h"
#include "Skeleton.h"

	struct [[nodiscard]] AnimationClip
	{
		const char* name = nullptr;
		bool isLooping = false;
		int nRepetition;
		float playTime;
		float playRate;
		std::vector<uruk::AnimationSample> animSamples;
	};
