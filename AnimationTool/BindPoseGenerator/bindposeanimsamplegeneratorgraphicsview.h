#ifndef BINDPOSEANIMSAMPLEGENERATORGRAPHICSVIEW_H
#define BINDPOSEANIMSAMPLEGENERATORGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QPointF>

class QMenu;
class QActionGroup;
class BindPoseAnimSampleGenerator;
struct Joint;
struct Sprite;
class JointGraphicsItem;
class SpriteGraphicsItem;

class BindPoseAnimSampleGeneratorGraphicsView : public QGraphicsView
{
    Q_OBJECT
    friend class MainWindow;
public:
    BindPoseAnimSampleGeneratorGraphicsView(QWidget *parent = nullptr);

    void AddJoint(const Joint& joint);
    void RemoveJoint(const Joint& joint);
    void SetJointName(const Joint& joint,QString name);

    void AddSprite(const Sprite& sprite);
    void RemoveSprite(const Sprite& sprite);
    void SetSpriteName(const Sprite& sprite);

    void paintEvent(QPaintEvent* event)override;
    int GetWidthPixel()const;
    int GetHeightPixel()const;

    JointGraphicsItem* GetJointGraphicsItemByName(const Joint& joint);
    SpriteGraphicsItem* GetSpriteGraphicsItemByName(const Sprite& sprite);
protected:
    void mousePressEvent(QMouseEvent* event)override;
    void mouseMoveEvent(QMouseEvent* event)override;
    void showEvent(QShowEvent* event) override;
    void resizeEvent(QResizeEvent* event)override;
private:
    QMenu* jointCreateMenu;
    QAction* createJointAction;
    QAction* createSpriteAction;
    QGraphicsScene* scene;
    BindPoseAnimSampleGenerator* parent;
    QGraphicsEllipseItem* skeletonSpaceOrigin;
    QVector<JointGraphicsItem*> jointGraphicsItems;
    QVector<SpriteGraphicsItem*> spriteGraphicsItems;
    QPoint mouseEventPos{0,0};
    void CreateActionMenu();
    int widthPixel;
    int heightPixel;
public slots:
    void SignalAddJointToAnimSampleGeneratorWidget();
    void setWidthPixel(int val);
    void setHeightPixel(int val);
};

#endif // BINDPOSEANIMSAMPLEGENERATORGRAPHICSVIEW_H
