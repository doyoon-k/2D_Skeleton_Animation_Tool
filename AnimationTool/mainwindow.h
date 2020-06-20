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

private:
    Ui::MainWindow *ui;
    inline static QMap<QString,QString> spriteNamePathPairs;
};

#endif // MAINWINDOW_H
