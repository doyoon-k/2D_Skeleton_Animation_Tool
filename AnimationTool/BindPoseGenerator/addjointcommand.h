#ifndef ADDJOINTCOMMAND_H
#define ADDJOINTCOMMAND_H
#include <QUndoCommand>
#include "Joint.h"

class BindPoseAnimSampleGenerator;

class AddJointCommand : public QUndoCommand
{
public:
    AddJointCommand(BindPoseAnimSampleGenerator* bindPoseAnimSanpleGeneratorWidget,const Joint& joint);
    void undo()override;
    void redo()override;
private:
    Joint joint;
    BindPoseAnimSampleGenerator* bindPoseAnimSanpleGeneratorWidget;
};

#endif // ADDJOINTCOMMAND_H
