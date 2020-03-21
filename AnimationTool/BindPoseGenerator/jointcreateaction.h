#ifndef CREATEJOINTACTION_H
#define CREATEJOINTACTION_H
#include <QAction>

class QString;

class JointCreateAction : public QAction
{
public:
    JointCreateAction(const QString& text,QObject* parent = nullptr);
};

#endif // CREATEJOINTACTION_H
