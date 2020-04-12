#ifndef ADDSPRITECOMMAND_H
#define ADDSPRITECOMMAND_H

#include <QUndoCommand>
#include <QSharedPointer>
#include <Sprite.h>

class BindPoseAnimSampleGenerator;

class AddSpriteCommand : public QUndoCommand
{
public:
    AddSpriteCommand(BindPoseAnimSampleGenerator* bindPoseAnimSanpleGeneratorWidget,QSharedPointer<Sprite> sprite);
    void undo()override;
    void redo()override;
private:
    QSharedPointer<Sprite> sprite;
    BindPoseAnimSampleGenerator* bindPoseAnimSanpleGeneratorWidget;
};

#endif // ADDSPRITECOMMAND_H
