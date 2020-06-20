#include "BindPoseGenerator/spritelistwidget.h"
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "spritegraphicsitem.h"
#include "jointgraphicsitem.h"
#include "Sprite.h"
#include <QObject>
#include <QKeyEvent>
#include "SpriteMesh.h"
#include "Skeleton.h"
#include "mainwindow.h"

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
}

SpriteMesh SpriteListWidget::GetSpriteMeshInstance(QString filename,Skeleton& skeleton)
{
    SpriteMesh spriteMesh;
    spriteMesh.name = filename + "SpriteMesh";
    spriteMesh.nSprites = count();
    spriteMesh.sprites.resize(spriteMesh.nSprites);
    for(int i = 0; i < count(); i++)
    {
        SpriteGraphicsItem* spriteItem = parent->GetGraphicsView()->GetSpriteGraphicsItemByName(item(i)->text());
        JointGraphicsItem* jointItem = parent->GetGraphicsView()->GetJointGraphicsItemByName(spriteItem->GetSprite()->parentJoint->name);
        int index = skeleton.GetJointIndexByName(jointItem->GetJoint()->name);
        spriteMesh.sprites[i].name = item(i)->text();
        spriteMesh.sprites[i].rotationOffset = 0;
        spriteMesh.sprites[i].connectedJointIndex = index;
        spriteMesh.sprites[i].bottomLeftCoord = Vector3D(spriteItem->pos().x(),spriteItem->pos().y());
        spriteMesh.sprites[i].bottomLeftCoord[0] /= parent->GetGraphicsView()->GetScalarWidthPixel();
        spriteMesh.sprites[i].bottomLeftCoord[1] /= parent->GetGraphicsView()->GetScalarHeightPixel();
    }
    return spriteMesh;
}

void SpriteListWidget::LoadFromSpriteMesh(const SpriteMesh &spriteMesh,const Skeleton& skeleton)
{
    for(int i = 0; i < spriteMesh.nSprites; i++)
    {
        QSharedPointer<Sprite> sprite(new Sprite(spriteMesh.sprites[i]));
        QString connectedJointName = skeleton.GetJoint(spriteMesh.sprites[i].connectedJointIndex).name;
        sprite->parentJoint = parent->GetGraphicsView()->GetJointGraphicsItemByName(connectedJointName)->GetJoint();
        QString imagePath = MainWindow::GetImagePathBySpriteName(sprite->name);
        sprite->image = QImage(imagePath);
        parent->AddSprite(sprite);
    }
}
