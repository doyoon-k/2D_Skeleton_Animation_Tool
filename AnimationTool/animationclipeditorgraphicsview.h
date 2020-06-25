#ifndef ANIMATIONCLIPEDITORGRAPHICSVIEW_H
#define ANIMATIONCLIPEDITORGRAPHICSVIEW_H

#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include <QElapsedTimer>

struct AnimationSample;
class AnimationClipEditorWidget;

class AnimationClipEditorGraphicsView : public BindPoseAnimSampleGeneratorGraphicsView
{
public:
    AnimationClipEditorGraphicsView(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void SetAnimationSample(const AnimationSample& animSample);
    void Reset();
private:
    QElapsedTimer timer;
    qreal prevTime = 0;
    AnimationClipEditorWidget* animationClipEditorWidget;
};

#endif // ANIMATIONCLIPEDITORGRAPHICSVIEW_H
