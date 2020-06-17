/********************************************************************************
** Form generated from reading UI file 'spritecreatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITECREATEDIALOG_H
#define UI_SPRITECREATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SpriteCreateDialog
{
public:
    QFormLayout *formLayout;
    QLabel *spriteNameLabel;
    QLineEdit *spriteNameLineEdit;
    QLabel *selectImageLabel;
    QListWidget *imageListWidget;
    QPushButton *createSpritePushButton;

    void setupUi(QDialog *SpriteCreateDialog)
    {
        if (SpriteCreateDialog->objectName().isEmpty())
            SpriteCreateDialog->setObjectName(QString::fromUtf8("SpriteCreateDialog"));
        SpriteCreateDialog->resize(392, 285);
        formLayout = new QFormLayout(SpriteCreateDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        spriteNameLabel = new QLabel(SpriteCreateDialog);
        spriteNameLabel->setObjectName(QString::fromUtf8("spriteNameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, spriteNameLabel);

        spriteNameLineEdit = new QLineEdit(SpriteCreateDialog);
        spriteNameLineEdit->setObjectName(QString::fromUtf8("spriteNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, spriteNameLineEdit);

        selectImageLabel = new QLabel(SpriteCreateDialog);
        selectImageLabel->setObjectName(QString::fromUtf8("selectImageLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, selectImageLabel);

        imageListWidget = new QListWidget(SpriteCreateDialog);
        imageListWidget->setObjectName(QString::fromUtf8("imageListWidget"));

        formLayout->setWidget(2, QFormLayout::SpanningRole, imageListWidget);

        createSpritePushButton = new QPushButton(SpriteCreateDialog);
        createSpritePushButton->setObjectName(QString::fromUtf8("createSpritePushButton"));

        formLayout->setWidget(3, QFormLayout::LabelRole, createSpritePushButton);


        retranslateUi(SpriteCreateDialog);

        QMetaObject::connectSlotsByName(SpriteCreateDialog);
    } // setupUi

    void retranslateUi(QDialog *SpriteCreateDialog)
    {
        SpriteCreateDialog->setWindowTitle(QCoreApplication::translate("SpriteCreateDialog", "Dialog", nullptr));
        spriteNameLabel->setText(QCoreApplication::translate("SpriteCreateDialog", "Sprite Name", nullptr));
        selectImageLabel->setText(QCoreApplication::translate("SpriteCreateDialog", "Select Image", nullptr));
        createSpritePushButton->setText(QCoreApplication::translate("SpriteCreateDialog", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpriteCreateDialog: public Ui_SpriteCreateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITECREATEDIALOG_H
