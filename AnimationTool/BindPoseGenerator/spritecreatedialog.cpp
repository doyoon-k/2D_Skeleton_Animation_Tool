#include "spritecreatedialog.h"
#include "ui_spritecreatedialog.h"
#include <QDebug>
#include <QMessageBox>

SpriteCreateDialog::SpriteCreateDialog(QListWidget* imageList,QWidget *parent) :
    QDialog(parent),
    imageList(imageList),
    ui(new Ui::SpriteCreateDialog)
{
    ui->setupUi(this);
    for(int i = 0; i < imageList->count(); i++)
    {
        ui->imageListWidget->addItem(new QListWidgetItem(*(imageList->item(i))));
    }
}

bool SpriteCreateDialog::IsSpriteCreated()
{
    return isSpriteCreated;
}

QString SpriteCreateDialog::GetCreatedSpriteName()
{
    return ui->spriteNameLineEdit->text();
}

QString SpriteCreateDialog::GetSelectedImagePath()
{
    return ui->imageListWidget->selectedItems()[0]->text();
}

SpriteCreateDialog::~SpriteCreateDialog()
{
    delete ui;
}

void SpriteCreateDialog::on_createSpritePushButton_clicked()
{
    if(imageList->count() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("No available Image.");
        msgBox.exec();
    }
    else
    {
        if(ui->spriteNameLineEdit->text().size() == 0)
        {
          QMessageBox msgBox;
          msgBox.setText("Name is not set.");
          msgBox.exec();
        }
        else
        {
            if(ui->imageListWidget->selectedItems().size() == 0)
            {
                QMessageBox msgBox;
                msgBox.setText("No image path selected.");
                msgBox.exec();
            }
            else
            {
                isSpriteCreated = true;
                close();
            }
        }
    }
}
