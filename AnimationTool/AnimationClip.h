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
        int nAnimSamples;
        std::vector<AnimationSample> animSamples;
	};

//    void LoadAnimationClip(QTextStream& stream,AnimationClip& animClip);

//    void SaveAnimationClip(QTextStream& stream,AnimationClip& animClip);

