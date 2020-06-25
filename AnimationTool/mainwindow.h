#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static QString GetImagePathBySpriteName(QString imageName);
    static void AddSpriteNamePathPair(QString spriteName,QString path);
    static void RemoveSpriteNamePathPair(QString spriteName);
private slots:

    void on_closeButton_clicked();

    void on_loadImagePushButton_clicked();

    void on_spriteOpacitySlider_valueChanged(int value);

    void on_saveBindPoseButton_clicked();
    
    void on_loadBindPoseButton_clicked();

    void on_widthPixelSpinBox_valueChanged(int arg1);

    void on_heightPixelSpinBox_valueChanged(int arg1);

    void on_LoadPushButton_clicked();

    void on_SavePushButton_clicked();

    void on_PlayPushButton_clicked();

    void on_StopPushButton_clicked();

    void on_ResumePushButton_clicked();

    void on_LoadAnimationClipPushButton_clicked();

    void on_SaveAnimationClipPushButton_clicked();

    void on_LoadAnimSamplePushButton_clicked();

    void on_ResetAnimSampleListPushButton_clicked();

private:
    Ui::MainWindow *ui;
    inline static QMap<QString,QString> spriteNamePathPairs;
};

#endif // MAINWINDOW_H
