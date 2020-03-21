#ifndef ADDJOINTCOMMAND_H
#define ADDJOINTCOMMAND_H
#include <QUndoCommand>


class AddJointCommand : public QUndoCommand
{
public:
    AddJointCommand();
    void undo()override;
    void redo()override;
};

#endif // ADDJOINTCOMMAND_H
