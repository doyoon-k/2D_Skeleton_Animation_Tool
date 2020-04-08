#pragma once
#include "AnimationSample.h"
#include "Skeleton.h"

	struct [[nodiscard]] AnimationClip
	{
        QString name;
		bool isLooping = false;
		int nRepetition;
		float playTime;
		float playRate;
        std::vector<AnimationSample> animSamples;
	};

    AnimationClip& LoadAnimationClip(QString path);
