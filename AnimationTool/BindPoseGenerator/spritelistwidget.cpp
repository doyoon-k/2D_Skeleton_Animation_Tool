#include "BindPoseGenerator/spritelistwidget.h"
#include "Sprite.h"
#include <QObject>

SpriteListWidget::SpriteListWidget(QWidget* parent)
    :QListWidget(parent)
{

}

void SpriteListWidget::AddSprite(const Sprite &sprite)
{
    addItem(sprite.name);
}

void SpriteListWidget::RemoveSprite(const Sprite &sprite)
{
    //proven safe by document.
    delete findItems(sprite.name,Qt::MatchExactly)[0];
}

void SpriteListWidget::keyPressEvent(QKeyEvent *event)
{

}
