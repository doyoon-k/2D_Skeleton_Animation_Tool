#ifndef SPRITELISTWIDGET_H
#define SPRITELISTWIDGET_H

#include <QListWidget>

class BindPoseAnimSampleGenerator;
struct Sprite;

class SpriteListWidget : public QListWidget
{
      Q_OBJECT
public:
    SpriteListWidget(QWidget* parent = nullptr);
    void AddSprite(const Sprite& sprite);
    void RemoveSprite(const Sprite& sprite);
    void keyPressEvent(QKeyEvent* event)override;
private:
    BindPoseAnimSampleGenerator* parent;
};

#endif // SPRITELISTWIDGET_H
