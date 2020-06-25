#ifndef ANIMATIONCLIPEDITOR_H
#define ANIMATIONCLIPEDITOR_H

#include <QWidget>

class QCheckBox;
class QSpinBox;
class QDoubleSpinBox;
class QListWidget;
class QSlider;
class AnimationClipEditorGraphicsView;
struct AnimationSample;
struct AnimationClip;

class AnimationClipEditorWidget : public QWidget
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit AnimationClipEditorWidget(QWidget *parent = nullptr);
    void Play();
    void Stop();
    void Resume();
    void AddTime(qreal elapsedTime);
    bool IsPlaying() const;
    AnimationSample GetLerpedAnimSample();
    void SetUpConnections();
    AnimationClip GetAnimationClip(QString name);
    void LoadFromAnimationClip(const AnimationClip& animClip);
    void Reset();
signals:
//    void SetSliderValueByElapsedTime(int sliderVal);
public slots:
    void SetElapsedTimeBySlider(int sliderVal);

private:
    QListWidget* animationSampleListWidget;
    AnimationClipEditorGraphicsView* animationSampleEditorGraphicsView;
    QDoubleSpinBox* playtimeSpinBox;
    QDoubleSpinBox* playRateSpinBox;
    QSpinBox*       nRepetitionSpinBox;
    QCheckBox*      isLoopingCheckBox;
    QSlider*        playSlider;
    qreal elapsedTime = 0;
    bool isPlaying = false;
};

#endif // ANIMATIONCLIPEDITOR_H
