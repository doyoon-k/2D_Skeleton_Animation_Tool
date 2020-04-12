#include "BindPoseGenerator/addspritecommand.h"
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include "BindPoseGenerator/spritelistwidget.h"

AddSpriteCommand::AddSpriteCommand(BindPoseAnimSampleGenerator *bindPoseAnimSanpleGeneratorWidget,QSharedPointer<Sprite> sprite)
    :QUndoCommand("Add Sprite"),sprite(sprite),bindPoseAnimSanpleGeneratorWidget(bindPoseAnimSanpleGeneratorWidget)
{

}

void AddSpriteCommand::undo()
{
    bindPoseAnimSanpleGeneratorWidget->graphicsView->RemoveSprite(sprite.data());
    bindPoseAnimSanpleGeneratorWidget->spriteListWidget->RemoveSprite(sprite.data());
}

void AddSpriteCommand::redo()
{
    bindPoseAnimSanpleGeneratorWidget->graphicsView->AddSprite(sprite);
    bindPoseAnimSanpleGeneratorWidget->spriteListWidget->AddSprite(sprite.data());
}
