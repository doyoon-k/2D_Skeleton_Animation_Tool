#ifndef ADDJOINTCOMMAND_H
#define ADDJOINTCOMMAND_H
#include <QUndoCommand>
#include <QSharedPointer>
#include "Joint.h"

class BindPoseAnimSampleGenerator;

class AddJointCommand : public QUndoCommand
{
public:
    AddJointCommand(BindPoseAnimSampleGenerator* bindPoseAnimSanpleGeneratorWidget,QSharedPointer<Joint> joint);
    void undo()override;
    void redo()override;
private:
    QSharedPointer<Joint> joint;
    BindPoseAnimSampleGenerator* bindPoseAnimSanpleGeneratorWidget;
};

#endif // ADDJOINTCOMMAND_H
