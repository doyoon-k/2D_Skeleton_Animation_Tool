#ifndef JOINTTREEWIDGETITEM_H
#define JOINTTREEWIDGETITEM_H
#include <QTreeWidgetItem>
#include "Joint.h"

class JointTreeWidgetItem : public QTreeWidgetItem
{
public:
    JointTreeWidgetItem(QTreeWidgetItem* parent, const Joint& joint);
//    void onDropEvent(JointTreeWidgetItem* newParent);
private:
    Joint jointData;
};

#endif // JOINTTREEWIDGETITEM_H
