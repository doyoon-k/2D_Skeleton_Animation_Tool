#ifndef ANIMATIONSAMPLELISTWIDGETITEM_H
#define ANIMATIONSAMPLELISTWIDGETITEM_H

#include <QListWidgetItem>
#include <AnimationSample.h>

class AnimationSampleListWidgetItem : public QListWidgetItem
{
public:
    AnimationSampleListWidgetItem(const AnimationSample& animSample);
    AnimationSample GetAnimSample();
private:
    AnimationSample animSample;
};

#endif // ANIMATIONSAMPLELISTWIDGETITEM_H
