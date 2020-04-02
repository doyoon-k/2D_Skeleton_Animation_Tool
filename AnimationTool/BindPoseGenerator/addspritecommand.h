#ifndef ADDSPRITECOMMAND_H
#define ADDSPRITECOMMAND_H

#include <QUndoCommand>
#include <Sprite.h>

class BindPoseAnimSampleGenerator;

class AddSpriteCommand : public QUndoCommand
{
public:
    AddSpriteCommand(BindPoseAnimSampleGenerator* bindPoseAnimSanpleGeneratorWidget,const Sprite& sprite);
    void undo()override;
    void redo()override;
private:
    Sprite sprite;
    BindPoseAnimSampleGenerator* bindPoseAnimSanpleGeneratorWidget;
};

#endif // ADDSPRITECOMMAND_H
