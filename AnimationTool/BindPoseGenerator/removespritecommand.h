#ifndef REMOVESPRITECOMMAND_H
#define REMOVESPRITECOMMAND_H
#include <QUndoCommand>
#include <QSharedPointer>
#include "Sprite.h"

class BindPoseAnimSampleGenerator;

class RemoveSpriteCommand : public QUndoCommand
{
public:
    RemoveSpriteCommand(BindPoseAnimSampleGenerator* bindPoseAnimSampleGeneratorWidget,QSharedPointer<Sprite> sprite);
    void undo()override;
    void redo()override;
private:
    QSharedPointer<Sprite> sprite;
    BindPoseAnimSampleGenerator* bindPoseAnimSampleGeneratorWidget;
};

#endif // REMOVESPRITECOMMAND_H
