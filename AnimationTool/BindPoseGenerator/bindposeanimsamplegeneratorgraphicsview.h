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

    void AddJoint(QSharedPointer<Joint> joint);
    void RemoveJoint(Joint* joint);
    void SetJointName(const Joint& joint,QString newName);

    void AddSprite(QSharedPointer<Sprite> sprite);
    void RemoveSprite(Sprite* sprite);
    void SetSpriteName(const Sprite& sprite,QString newName);
    void SetSpriteGraphicsItemsOpacity(qreal opacity);

    void paintEvent(QPaintEvent* event)override;
    int GetWidthPixel()const;
    int GetHeightPixel()const;
    qreal GetScalarWidthPixel();
    qreal GetScalarHeightPixel();

    JointGraphicsItem* GetJointGraphicsItemByName(const QString& jointName);
    SpriteGraphicsItem* GetSpriteGraphicsItemByName(const QString& spriteName);
protected:
    void mousePressEvent(QMouseEvent* event)override;
    void mouseMoveEvent(QMouseEvent* event)override;
    void showEvent(QShowEvent* event) override;
    void resizeEvent(QResizeEvent* event)override;
private:
    QMenu* joint_sprite_CreateMenu;
    QAction* createJointAction;
    QAction* createSpriteAction;
    QGraphicsScene* scene;
    BindPoseAnimSampleGenerator* parent;
    QGraphicsRectItem* skeletonSpaceOrigin;
    QVector<JointGraphicsItem*> jointGraphicsItems;
    QVector<SpriteGraphicsItem*> spriteGraphicsItems;
    QPoint mouseRightClickEventPos{0,0};
    void CreateActionMenu();
    int widthPixel;
    int heightPixel;
    void RescaleGraphicsItems();
public slots:
    void SignalAddJointToAnimSampleGeneratorWidget();
    void SignalAddSpriteToAnimSampleGeneratorWidget();
    void setWidthPixel(int val);
    void setHeightPixel(int val);
};

#endif // BINDPOSEANIMSAMPLEGENERATORGRAPHICSVIEW_H
