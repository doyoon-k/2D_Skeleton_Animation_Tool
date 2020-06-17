#ifndef SPRITELISTWIDGET_H
#define SPRITELISTWIDGET_H

#include <QListWidget>

class BindPoseAnimSampleGenerator;
struct Sprite;
struct SpriteMesh;
class Skeleton;

class SpriteListWidget : public QListWidget
{
      Q_OBJECT
public:
    SpriteListWidget(QWidget* parent = nullptr);
    void AddSprite(Sprite* sprite);
    void RemoveSprite(Sprite* sprite);
    void keyPressEvent(QKeyEvent* event)override;

    SpriteMesh GetSpriteMeshInstance(QString filename,Skeleton& skeleton);
private:
    BindPoseAnimSampleGenerator* parent;
};

#endif // SPRITELISTWIDGET_H
