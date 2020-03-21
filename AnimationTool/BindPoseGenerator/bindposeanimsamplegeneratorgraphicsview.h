#ifndef BINDPOSEANIMSAMPLEGENERATORGRAPHICSVIEW_H
#define BINDPOSEANIMSAMPLEGENERATORGRAPHICSVIEW_H
#include <QGraphicsView>

class QMenu;
class QActionGroup;

class BindPoseAnimSampleGeneratorGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    BindPoseAnimSampleGeneratorGraphicsView(QWidget *parent = nullptr);
protected:
//    void contextMenuEvent(QContextMenuEvent* event)override;
    void mousePressEvent(QMouseEvent* event)override;
private:
    QMenu* jointCreateMenu;
    QAction* createJointAction;

public slots:
      void Test();
};

#endif // BINDPOSEANIMSAMPLEGENERATORGRAPHICSVIEW_H
