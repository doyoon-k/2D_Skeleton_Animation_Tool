#include "removespritecommand.h"
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "BindPoseGenerator/spritelistwidget.h"

RemoveSpriteCommand::RemoveSpriteCommand(BindPoseAnimSampleGenerator *bindPoseAnimSampleGeneratorWidget,QSharedPointer<Sprite> sprite)
    :QUndoCommand ("Remove Sprite"),sprite(sprite),bindPoseAnimSampleGeneratorWidget(bindPoseAnimSampleGeneratorWidget)
{

}

void RemoveSpriteCommand::undo()
{
    bindPoseAnimSampleGeneratorWidget->graphicsView->AddSprite(sprite);
    bindPoseAnimSampleGeneratorWidget->spriteListWidget->AddSprite(sprite.data());
}

void RemoveSpriteCommand::redo()
{
    bindPoseAnimSampleGeneratorWidget->graphicsView->RemoveSprite(sprite.data());
    bindPoseAnimSampleGeneratorWidget->spriteListWidget->RemoveSprite(sprite.data());
}
