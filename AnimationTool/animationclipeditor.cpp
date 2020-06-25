#include "animationclipeditor.h"
#include "AnimationSample.h"
#include "AnimationClip.h"
#include "animationsamplelistwidgetitem.h"
#include "animationclipeditorgraphicsview.h"
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QListWidget>
#include <QSlider>
#include <QDebug>

AnimationClipEditorWidget::AnimationClipEditorWidget(QWidget *parent) : QWidget(parent)
{

}

void AnimationClipEditorWidget::Play()
{
    elapsedTime = 0;
    isPlaying = true;
}

void AnimationClipEditorWidget::Stop()
{
    isPlaying = false;
}

void AnimationClipEditorWidget::Resume()
{
    isPlaying = true;
}

void AnimationClipEditorWidget::AddTime(qreal elapsedTime)
{
    this->elapsedTime += elapsedTime;
}

bool AnimationClipEditorWidget::IsPlaying() const
{
    return isPlaying && playtimeSpinBox->value() > 0 && playRateSpinBox->value() > 0 && animationSampleListWidget->count() > 0;
}

AnimationSample AnimationClipEditorWidget::GetLerpedAnimSample()
{
    double playTime = playtimeSpinBox->value();
    double playRate = playRateSpinBox->value();
    double nRepetition = (double)nRepetitionSpinBox->value();
    bool isLooping = isLoopingCheckBox->isChecked();
    int nAnimSamples = animationSampleListWidget->count();
    qreal local_t;
    qreal keyTimeChunk = playTime/static_cast<float>(nAnimSamples - 1);

    if(isLooping)
    {
        local_t = std::fmod(playRate*this->elapsedTime,playTime);
    }
    else
    {
        local_t = std::fmod(std::clamp(playRate*this->elapsedTime,0.0,nRepetition*playTime),playTime);
    }


    int prevAnimSampleIndex = static_cast<int>(local_t/keyTimeChunk);
    int nextAnimSampleIndex = std::clamp((prevAnimSampleIndex + 1),0,nAnimSamples-1);
    float keyTime = keyTimeChunk * static_cast<float>(prevAnimSampleIndex);
    float lerp_t = (local_t - keyTime) / keyTimeChunk;

    if(nAnimSamples == 1)
    {
        return static_cast<AnimationSampleListWidgetItem*>(animationSampleListWidget->item(0))->GetAnimSample();
    }

    AnimationSample prevAnimSample = static_cast<AnimationSampleListWidgetItem*>(animationSampleListWidget->item(prevAnimSampleIndex))->GetAnimSample();
    AnimationSample nextAnimSample = static_cast<AnimationSampleListWidgetItem*>(animationSampleListWidget->item(nextAnimSampleIndex))->GetAnimSample();

//    qDebug()<<"locat_t : "<<local_t<<endl;
//    qDebug()<<"keyTime : "<<keyTime<<endl;
//    qDebug()<<"prevAnimIndex : "<<prevAnimSampleIndex<<" nextAnimIndex : "<<nextAnimSampleIndex<<endl;
//    qDebug()<<"lerp_t : "<<lerp_t<<endl;

    return LerpAnimSample(prevAnimSample,nextAnimSample,lerp_t);
}

//void AnimationClipEditorWidget::SetSliderValueByElapsedTime(int sliderVal)
//{
//    Stop();
//}

void AnimationClipEditorWidget::SetUpConnections()
{
    connect(playSlider,SIGNAL(valueChanged(int)),this,SLOT(SetElapsedTimeBySlider(int)));
}

AnimationClip AnimationClipEditorWidget::GetAnimationClip(QString name)
{
    AnimationClip animClip;
    animClip.name = name;
    animClip.playRate = playRateSpinBox->value();
    animClip.playTime = playtimeSpinBox->value();
    animClip.isLooping = isLoopingCheckBox->isChecked();
    animClip.nRepetition = nRepetitionSpinBox->value();
    animClip.nAnimSamples = animationSampleListWidget->count();
    for(int i = 0; i < animClip.nAnimSamples; i++)
    {
        AnimationSample animSample = static_cast<AnimationSampleListWidgetItem*>(animationSampleListWidget->item(i))->GetAnimSample();
        for(int i = 0; i < animSample.skeleton.GetNumbertOfJoints(); i++)
        {
            Joint& joint = animSample.skeleton.GetJoint(i);
            joint.position[0] /= animationSampleEditorGraphicsView->GetScalarWidthPixel();
            joint.position[1] /= animationSampleEditorGraphicsView->GetScalarHeightPixel();
        }
        for(int i = 0; i < animSample.spriteMesh.nSprites; i++)
        {
            Sprite& sprite = animSample.spriteMesh.sprites[i];
            sprite.bottomLeftCoord[0] /= animationSampleEditorGraphicsView->GetScalarWidthPixel();
            sprite.bottomLeftCoord[1] /= animationSampleEditorGraphicsView->GetScalarHeightPixel();
        }
        animClip.animSamples.push_back(animSample);
    }

    return animClip;
}

void AnimationClipEditorWidget::Reset()
{
    animationSampleListWidget->clear();
    animationSampleEditorGraphicsView->Reset();
    playtimeSpinBox->clear();
    playRateSpinBox->clear();
    nRepetitionSpinBox->clear();
    isLoopingCheckBox->setChecked(false);
    playSlider->setValue(0);
}

void AnimationClipEditorWidget::SetElapsedTimeBySlider(int sliderVal)
{
    this->elapsedTime = (float)sliderVal/float(playSlider->maximum()) * playtimeSpinBox->value();
    qDebug()<<this->elapsedTime<<endl;
}
