#ifndef ANIMSAMPLEEDITORGRAPHICSVIEW_H
#define ANIMSAMPLEEDITORGRAPHICSVIEW_H
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
class Skeleton;
struct SpriteMesh;
class JointGraphicsItem;
class SpriteGraphicsItem;
struct AnimationSample;

class AnimSampleEditorGraphicsView : public BindPoseAnimSampleGeneratorGraphicsView
{
public:
    AnimSampleEditorGraphicsView(QWidget* parent);
    void LoadAnimSample(const Skeleton& skeleton,const SpriteMesh& spriteMesh);
//    AnimationSample GetAnimSample() const;
private:
};

#endif // ANIMSAMPLEEDITORGRAPHICSVIEW_H
