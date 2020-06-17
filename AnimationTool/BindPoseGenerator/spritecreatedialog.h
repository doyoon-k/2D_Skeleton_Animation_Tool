#ifndef SPRITECREATEDIALOG_H
#define SPRITECREATEDIALOG_H

#include <QDialog>

namespace Ui
{
class SpriteCreateDialog;
}

class QListWidget;

class SpriteCreateDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SpriteCreateDialog(QListWidget* imageList,QWidget *parent = nullptr);
    bool IsSpriteCreated();
    QString GetCreatedSpriteName();
    QString GetSelectedImagePath();
    ~SpriteCreateDialog();
private slots:
    void on_createSpritePushButton_clicked();
private:
    bool isSpriteCreated = false;
    QListWidget* imageList;
    Ui::SpriteCreateDialog *ui;
};

#endif // SPRITECREATEDIALOG_H
