#ifndef REMOVEJOINTCOMMAND_H
#define REMOVEJOINTCOMMAND_H

#include <QUndoCommand>
#include <QSharedPointer>
#include "Joint.h"

class BindPoseAnimSampleGenerator;

class RemoveJointCommand : public QUndoCommand
{
public:
    RemoveJointCommand(BindPoseAnimSampleGenerator* bindPoseAnimSampleGeneratorWidget,QSharedPointer<Joint> joint);
    void undo()override;
    void redo()override;
private:
    QSharedPointer<Joint> joint;
    BindPoseAnimSampleGenerator* bindPoseAnimSampleGeneratorWidget;
};

#endif // REMOVEJOINTCOMMAND_H
