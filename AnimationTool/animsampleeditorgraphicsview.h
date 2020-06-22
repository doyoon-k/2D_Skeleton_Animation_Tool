#ifndef ANIMSAMPLEEDITORGRAPHICSVIEW_H
#define ANIMSAMPLEEDITORGRAPHICSVIEW_H
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include <unordered_map>
#include <vector>
#include "Vector3D.h"

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

    void mousePressEvent(QMouseEvent* event)override;
    void mouseReleaseEvent(QMouseEvent* event)override;
    void mouseMoveEvent(QMouseEvent* event)override;

    void Reset();
private:
    QGraphicsItem* currentSelectedItem = nullptr;
    std::unordered_map<int,std::vector<int>> skeletonIndexChildMap;
    std::vector<Vector3D> jointOffsetFromParent;
};

#endif // ANIMSAMPLEEDITORGRAPHICSVIEW_H
