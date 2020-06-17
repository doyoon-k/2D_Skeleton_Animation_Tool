#include "BindPoseGenerator/spritelistwidget.h"
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "spritegraphicsitem.h"
#include "Sprite.h"
#include <QObject>
#include <QKeyEvent>
#include "SpriteMesh.h"
#include "Skeleton.h"

SpriteListWidget::SpriteListWidget(QWidget* parent)
    :QListWidget(parent)
{
    this->parent = static_cast<BindPoseAnimSampleGenerator*>(parent);
}

void SpriteListWidget::AddSprite(Sprite* sprite)
{
    addItem(sprite->name);
}

void SpriteListWidget::RemoveSprite(Sprite* sprite)
{
    //proven safe by document.
    delete findItems(sprite->name,Qt::MatchExactly)[0];
}

void SpriteListWidget::keyPressEvent(QKeyEvent *event)
{
    ushort key = event->text()[0].unicode();
    if(count() == 0)
        return;

    QListWidgetItem* item = selectedItems()[0];
    QString spriteName = item->text();
    SpriteGraphicsItem* spriteItem = parent->graphicsView->GetSpriteGraphicsItemByName(spriteName);
    QSharedPointer<Sprite> sprite = spriteItem->GetSprite();

    if(event->key() == Qt::Key_Delete)
    {
        parent->RemoveSprite(sprite);
        return;
    }
    else if(event->key() == Qt::Key_Backspace && spriteName.size() > 0)
    {
        spriteName.resize(spriteName.size()-1);
    }
    else if((Qt::Key_0 <= key && key <= Qt::Key_9) ||
            (QChar('a').unicode() <= key && key <= QChar('z').unicode()) ||
             event->key() == Qt::Key_Underscore)
    {
        spriteName.push_back(key);
    }
    item->setText(spriteName);
    parent->SetSpriteName(*sprite,spriteName);
    QListWidget::keyPressEvent(event);
}

SpriteMesh SpriteListWidget::GetSpriteMeshInstance(QString filename,Skeleton& skeleton)
{
    SpriteMesh spriteMesh;
    spriteMesh.name = filename + "SpriteMesh";
    spriteMesh.nSprites = count();
    for(int i = 0; i < count(); i++)
    {
        QString parentJointName = static_cast<SpriteGraphicsItem*>(parent->GetGraphicsView()->GetSpriteGraphicsItemByName(item(i)->text()))->GetSprite()->name;
        int index = skeleton.GetJointIndexByName(parentJointName);
        spriteMesh.sprites[i].name = item(i)->text();
        spriteMesh.sprites[i].rotationOffset = 0;
        spriteMesh.sprites[i].connectedJointIndex = index;
    }
    return spriteMesh;
}
