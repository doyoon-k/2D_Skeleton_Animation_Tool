#include "animationsamplelistwidgetitem.h"

AnimationSampleListWidgetItem::AnimationSampleListWidgetItem(const AnimationSample& animSample)
    :QListWidgetItem(),animSample(animSample)
{
    setText(animSample.name);
}

AnimationSample AnimationSampleListWidgetItem::GetAnimSample()
{
    return animSample;
}
