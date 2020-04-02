#include "BindPoseGenerator/addspritecommand.h"
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include "BindPoseGenerator/spritelistwidget.h"

AddSpriteCommand::AddSpriteCommand(BindPoseAnimSampleGenerator *bindPoseAnimSanpleGeneratorWidget, const Sprite &sprite)
    :sprite(sprite),bindPoseAnimSanpleGeneratorWidget(bindPoseAnimSanpleGeneratorWidget)
{

}

void AddSpriteCommand::undo()
{
    bindPoseAnimSanpleGeneratorWidget->RemoveSprite(sprite);
}

void AddSpriteCommand::redo()
{
    bindPoseAnimSanpleGeneratorWidget->graphicsView->AddSprite(sprite);
    bindPoseAnimSanpleGeneratorWidget->spriteListWidget->AddSprite(sprite);
}
