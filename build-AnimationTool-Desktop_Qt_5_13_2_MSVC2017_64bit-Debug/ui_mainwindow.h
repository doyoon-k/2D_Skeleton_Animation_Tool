/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include "BindPoseGenerator/skeletonhierarchytreewidget.h"
#include "BindPoseGenerator/spritelistwidget.h"
#include "animationclipeditor.h"
#include "animationclipeditorgraphicsview.h"
#include "animsampleeditorgraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *closeButton;
    QTabWidget *animSampleClipBindposeTab;
    BindPoseAnimSampleGenerator *bindPoseGeneratorWidget;
    QGridLayout *gridLayout_2;
    QSlider *spriteOpacitySlider;
    QSpinBox *widthPixelSpinBox;
    QPushButton *loadImagePushButton;
    QPushButton *loadBindPoseButton;
    QSpinBox *heightPixelSpinBox;
    BindPoseAnimSampleGeneratorGraphicsView *bindposeGraphicsView;
    QLabel *spriteOpacityLabel;
    QLabel *HeightPixelLabel;
    QLabel *imagesLabel;
    QLabel *spritesLabel;
    QListWidget *imagesList;
    SpriteListWidget *spriteList;
    QLabel *skeletonHierarchyLabel;
    SkeletonHierarchyTreeWidget *skeletonHierarchyTree;
    QPushButton *saveBindPoseButton;
    QLabel *WidthPixelLabel;
    QWidget *animationSampleEditorWidget;
    QGridLayout *gridLayout_3;
    AnimSampleEditorGraphicsView *AnimSampleEditorGraphicView;
    QPushButton *LoadPushButton;
    QPushButton *SavePushButton;
    AnimationClipEditorWidget *animationClipEditorWidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QCheckBox *IsLoopingCheckBox;
    QHBoxLayout *horizontalLayout;
    QLabel *RepetitionLabel;
    QSpinBox *RepetitionSpinbox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *PlaytimeLabel;
    QDoubleSpinBox *PlaytimeDoubleSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *PlayRateLabel;
    QDoubleSpinBox *PlayRateDoubleSpinBox;
    QVBoxLayout *verticalLayout_2;
    QSlider *AnimationPlaySlider;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *PlayPushButton;
    QPushButton *StopPushButton;
    QPushButton *ResumePushButton;
    QListWidget *AnimationSampleListWidget;
    QPushButton *LoadAnimSamplePushButton;
    AnimationClipEditorGraphicsView *AnimationClipGraphicsView;
    QPushButton *ResetAnimSampleListPushButton;
    QPushButton *SaveAnimationClipPushButton;
    QPushButton *LoadAnimationClipPushButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAnimationTool;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 985);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMaximumSize(QSize(100, 100));

        gridLayout->addWidget(closeButton, 2, 0, 1, 1);

        animSampleClipBindposeTab = new QTabWidget(centralwidget);
        animSampleClipBindposeTab->setObjectName(QString::fromUtf8("animSampleClipBindposeTab"));
        animSampleClipBindposeTab->setMinimumSize(QSize(800, 0));
        bindPoseGeneratorWidget = new BindPoseAnimSampleGenerator();
        bindPoseGeneratorWidget->setObjectName(QString::fromUtf8("bindPoseGeneratorWidget"));
        gridLayout_2 = new QGridLayout(bindPoseGeneratorWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        spriteOpacitySlider = new QSlider(bindPoseGeneratorWidget);
        spriteOpacitySlider->setObjectName(QString::fromUtf8("spriteOpacitySlider"));
        spriteOpacitySlider->setMaximumSize(QSize(800, 16777215));
        spriteOpacitySlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(spriteOpacitySlider, 15, 2, 1, 1);

        widthPixelSpinBox = new QSpinBox(bindPoseGeneratorWidget);
        widthPixelSpinBox->setObjectName(QString::fromUtf8("widthPixelSpinBox"));
        widthPixelSpinBox->setMaximumSize(QSize(200, 200));
        widthPixelSpinBox->setMaximum(2000);
        widthPixelSpinBox->setValue(100);

        gridLayout_2->addWidget(widthPixelSpinBox, 2, 2, 1, 1);

        loadImagePushButton = new QPushButton(bindPoseGeneratorWidget);
        loadImagePushButton->setObjectName(QString::fromUtf8("loadImagePushButton"));
        loadImagePushButton->setMaximumSize(QSize(800, 16777215));

        gridLayout_2->addWidget(loadImagePushButton, 18, 2, 1, 1);

        loadBindPoseButton = new QPushButton(bindPoseGeneratorWidget);
        loadBindPoseButton->setObjectName(QString::fromUtf8("loadBindPoseButton"));
        loadBindPoseButton->setMaximumSize(QSize(800, 200));

        gridLayout_2->addWidget(loadBindPoseButton, 19, 0, 1, 1);

        heightPixelSpinBox = new QSpinBox(bindPoseGeneratorWidget);
        heightPixelSpinBox->setObjectName(QString::fromUtf8("heightPixelSpinBox"));
        heightPixelSpinBox->setMaximumSize(QSize(200, 200));
        heightPixelSpinBox->setMaximum(2000);
        heightPixelSpinBox->setValue(100);

        gridLayout_2->addWidget(heightPixelSpinBox, 5, 2, 1, 1);

        bindposeGraphicsView = new BindPoseAnimSampleGeneratorGraphicsView(bindPoseGeneratorWidget);
        bindposeGraphicsView->setObjectName(QString::fromUtf8("bindposeGraphicsView"));
        bindposeGraphicsView->setMinimumSize(QSize(800, 800));
        bindposeGraphicsView->setMaximumSize(QSize(800, 800));
        bindposeGraphicsView->setMouseTracking(true);
        bindposeGraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        bindposeGraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        bindposeGraphicsView->setDragMode(QGraphicsView::RubberBandDrag);

        gridLayout_2->addWidget(bindposeGraphicsView, 0, 0, 19, 1);

        spriteOpacityLabel = new QLabel(bindPoseGeneratorWidget);
        spriteOpacityLabel->setObjectName(QString::fromUtf8("spriteOpacityLabel"));
        spriteOpacityLabel->setMaximumSize(QSize(800, 16777215));

        gridLayout_2->addWidget(spriteOpacityLabel, 14, 2, 1, 1);

        HeightPixelLabel = new QLabel(bindPoseGeneratorWidget);
        HeightPixelLabel->setObjectName(QString::fromUtf8("HeightPixelLabel"));
        HeightPixelLabel->setMaximumSize(QSize(200, 200));

        gridLayout_2->addWidget(HeightPixelLabel, 3, 2, 1, 1);

        imagesLabel = new QLabel(bindPoseGeneratorWidget);
        imagesLabel->setObjectName(QString::fromUtf8("imagesLabel"));

        gridLayout_2->addWidget(imagesLabel, 16, 2, 1, 1);

        spritesLabel = new QLabel(bindPoseGeneratorWidget);
        spritesLabel->setObjectName(QString::fromUtf8("spritesLabel"));

        gridLayout_2->addWidget(spritesLabel, 12, 2, 1, 1);

        imagesList = new QListWidget(bindPoseGeneratorWidget);
        imagesList->setObjectName(QString::fromUtf8("imagesList"));
        imagesList->setMaximumSize(QSize(800, 16777215));

        gridLayout_2->addWidget(imagesList, 17, 2, 1, 1);

        spriteList = new SpriteListWidget(bindPoseGeneratorWidget);
        spriteList->setObjectName(QString::fromUtf8("spriteList"));
        spriteList->setMaximumSize(QSize(800, 16777215));

        gridLayout_2->addWidget(spriteList, 13, 2, 1, 1);

        skeletonHierarchyLabel = new QLabel(bindPoseGeneratorWidget);
        skeletonHierarchyLabel->setObjectName(QString::fromUtf8("skeletonHierarchyLabel"));

        gridLayout_2->addWidget(skeletonHierarchyLabel, 8, 2, 1, 1);

        skeletonHierarchyTree = new SkeletonHierarchyTreeWidget(bindPoseGeneratorWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        skeletonHierarchyTree->setHeaderItem(__qtreewidgetitem);
        skeletonHierarchyTree->setObjectName(QString::fromUtf8("skeletonHierarchyTree"));
        skeletonHierarchyTree->setMaximumSize(QSize(800, 16777215));
        skeletonHierarchyTree->setMouseTracking(true);
        skeletonHierarchyTree->setAcceptDrops(true);
        skeletonHierarchyTree->setDragEnabled(true);
        skeletonHierarchyTree->setDragDropMode(QAbstractItemView::InternalMove);
        skeletonHierarchyTree->setColumnCount(1);

        gridLayout_2->addWidget(skeletonHierarchyTree, 9, 2, 1, 1);

        saveBindPoseButton = new QPushButton(bindPoseGeneratorWidget);
        saveBindPoseButton->setObjectName(QString::fromUtf8("saveBindPoseButton"));
        saveBindPoseButton->setMaximumSize(QSize(800, 200));

        gridLayout_2->addWidget(saveBindPoseButton, 20, 0, 1, 1);

        WidthPixelLabel = new QLabel(bindPoseGeneratorWidget);
        WidthPixelLabel->setObjectName(QString::fromUtf8("WidthPixelLabel"));
        WidthPixelLabel->setMaximumSize(QSize(200, 200));

        gridLayout_2->addWidget(WidthPixelLabel, 1, 2, 1, 1);

        animSampleClipBindposeTab->addTab(bindPoseGeneratorWidget, QString());
        animationSampleEditorWidget = new QWidget();
        animationSampleEditorWidget->setObjectName(QString::fromUtf8("animationSampleEditorWidget"));
        gridLayout_3 = new QGridLayout(animationSampleEditorWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        AnimSampleEditorGraphicView = new AnimSampleEditorGraphicsView(animationSampleEditorWidget);
        AnimSampleEditorGraphicView->setObjectName(QString::fromUtf8("AnimSampleEditorGraphicView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AnimSampleEditorGraphicView->sizePolicy().hasHeightForWidth());
        AnimSampleEditorGraphicView->setSizePolicy(sizePolicy1);
        AnimSampleEditorGraphicView->setMinimumSize(QSize(0, 0));
        AnimSampleEditorGraphicView->setMaximumSize(QSize(800, 800));
        AnimSampleEditorGraphicView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        AnimSampleEditorGraphicView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_3->addWidget(AnimSampleEditorGraphicView, 0, 0, 2, 1);

        LoadPushButton = new QPushButton(animationSampleEditorWidget);
        LoadPushButton->setObjectName(QString::fromUtf8("LoadPushButton"));

        gridLayout_3->addWidget(LoadPushButton, 2, 1, 1, 1);

        SavePushButton = new QPushButton(animationSampleEditorWidget);
        SavePushButton->setObjectName(QString::fromUtf8("SavePushButton"));

        gridLayout_3->addWidget(SavePushButton, 3, 1, 1, 1);

        animSampleClipBindposeTab->addTab(animationSampleEditorWidget, QString());
        animationClipEditorWidget = new AnimationClipEditorWidget();
        animationClipEditorWidget->setObjectName(QString::fromUtf8("animationClipEditorWidget"));
        gridLayout_5 = new QGridLayout(animationClipEditorWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        IsLoopingCheckBox = new QCheckBox(animationClipEditorWidget);
        IsLoopingCheckBox->setObjectName(QString::fromUtf8("IsLoopingCheckBox"));

        verticalLayout->addWidget(IsLoopingCheckBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        RepetitionLabel = new QLabel(animationClipEditorWidget);
        RepetitionLabel->setObjectName(QString::fromUtf8("RepetitionLabel"));

        horizontalLayout->addWidget(RepetitionLabel);

        RepetitionSpinbox = new QSpinBox(animationClipEditorWidget);
        RepetitionSpinbox->setObjectName(QString::fromUtf8("RepetitionSpinbox"));
        RepetitionSpinbox->setValue(1);

        horizontalLayout->addWidget(RepetitionSpinbox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        PlaytimeLabel = new QLabel(animationClipEditorWidget);
        PlaytimeLabel->setObjectName(QString::fromUtf8("PlaytimeLabel"));

        horizontalLayout_2->addWidget(PlaytimeLabel);

        PlaytimeDoubleSpinBox = new QDoubleSpinBox(animationClipEditorWidget);
        PlaytimeDoubleSpinBox->setObjectName(QString::fromUtf8("PlaytimeDoubleSpinBox"));
        PlaytimeDoubleSpinBox->setValue(5.000000000000000);

        horizontalLayout_2->addWidget(PlaytimeDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PlayRateLabel = new QLabel(animationClipEditorWidget);
        PlayRateLabel->setObjectName(QString::fromUtf8("PlayRateLabel"));

        horizontalLayout_3->addWidget(PlayRateLabel);

        PlayRateDoubleSpinBox = new QDoubleSpinBox(animationClipEditorWidget);
        PlayRateDoubleSpinBox->setObjectName(QString::fromUtf8("PlayRateDoubleSpinBox"));
        PlayRateDoubleSpinBox->setValue(1.000000000000000);

        horizontalLayout_3->addWidget(PlayRateDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_4->addLayout(verticalLayout, 3, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        AnimationPlaySlider = new QSlider(animationClipEditorWidget);
        AnimationPlaySlider->setObjectName(QString::fromUtf8("AnimationPlaySlider"));
        AnimationPlaySlider->setMaximum(100);
        AnimationPlaySlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(AnimationPlaySlider);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        PlayPushButton = new QPushButton(animationClipEditorWidget);
        PlayPushButton->setObjectName(QString::fromUtf8("PlayPushButton"));

        horizontalLayout_4->addWidget(PlayPushButton);

        StopPushButton = new QPushButton(animationClipEditorWidget);
        StopPushButton->setObjectName(QString::fromUtf8("StopPushButton"));

        horizontalLayout_4->addWidget(StopPushButton);

        ResumePushButton = new QPushButton(animationClipEditorWidget);
        ResumePushButton->setObjectName(QString::fromUtf8("ResumePushButton"));

        horizontalLayout_4->addWidget(ResumePushButton);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout_4->addLayout(verticalLayout_2, 3, 0, 1, 1);

        AnimationSampleListWidget = new QListWidget(animationClipEditorWidget);
        AnimationSampleListWidget->setObjectName(QString::fromUtf8("AnimationSampleListWidget"));

        gridLayout_4->addWidget(AnimationSampleListWidget, 0, 1, 1, 1);

        LoadAnimSamplePushButton = new QPushButton(animationClipEditorWidget);
        LoadAnimSamplePushButton->setObjectName(QString::fromUtf8("LoadAnimSamplePushButton"));

        gridLayout_4->addWidget(LoadAnimSamplePushButton, 1, 1, 1, 1);

        AnimationClipGraphicsView = new AnimationClipEditorGraphicsView(animationClipEditorWidget);
        AnimationClipGraphicsView->setObjectName(QString::fromUtf8("AnimationClipGraphicsView"));
        AnimationClipGraphicsView->setMinimumSize(QSize(600, 600));
        AnimationClipGraphicsView->setMaximumSize(QSize(600, 600));
        AnimationClipGraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        AnimationClipGraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_4->addWidget(AnimationClipGraphicsView, 0, 0, 1, 1);

        ResetAnimSampleListPushButton = new QPushButton(animationClipEditorWidget);
        ResetAnimSampleListPushButton->setObjectName(QString::fromUtf8("ResetAnimSampleListPushButton"));

        gridLayout_4->addWidget(ResetAnimSampleListPushButton, 2, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        SaveAnimationClipPushButton = new QPushButton(animationClipEditorWidget);
        SaveAnimationClipPushButton->setObjectName(QString::fromUtf8("SaveAnimationClipPushButton"));

        gridLayout_5->addWidget(SaveAnimationClipPushButton, 2, 0, 1, 1);

        LoadAnimationClipPushButton = new QPushButton(animationClipEditorWidget);
        LoadAnimationClipPushButton->setObjectName(QString::fromUtf8("LoadAnimationClipPushButton"));

        gridLayout_5->addWidget(LoadAnimationClipPushButton, 1, 0, 1, 1);

        animSampleClipBindposeTab->addTab(animationClipEditorWidget, QString());

        gridLayout->addWidget(animSampleClipBindposeTab, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        menuAnimationTool = new QMenu(menubar);
        menuAnimationTool->setObjectName(QString::fromUtf8("menuAnimationTool"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAnimationTool->menuAction());

        retranslateUi(MainWindow);

        animSampleClipBindposeTab->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        loadImagePushButton->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        loadBindPoseButton->setText(QCoreApplication::translate("MainWindow", "Load BindPose", nullptr));
        spriteOpacityLabel->setText(QCoreApplication::translate("MainWindow", "Sprite Opacity", nullptr));
        HeightPixelLabel->setText(QCoreApplication::translate("MainWindow", "Height Pixel", nullptr));
        imagesLabel->setText(QCoreApplication::translate("MainWindow", "Images ", nullptr));
        spritesLabel->setText(QCoreApplication::translate("MainWindow", "Sprites", nullptr));
        skeletonHierarchyLabel->setText(QCoreApplication::translate("MainWindow", "Skeleton Hierarchy", nullptr));
        saveBindPoseButton->setText(QCoreApplication::translate("MainWindow", "Save BindPose", nullptr));
        WidthPixelLabel->setText(QCoreApplication::translate("MainWindow", "Width Pixel", nullptr));
        animSampleClipBindposeTab->setTabText(animSampleClipBindposeTab->indexOf(bindPoseGeneratorWidget), QCoreApplication::translate("MainWindow", "BindPose Generator", nullptr));
        LoadPushButton->setText(QCoreApplication::translate("MainWindow", "Load AnimSample", nullptr));
        SavePushButton->setText(QCoreApplication::translate("MainWindow", "Save AnimSample", nullptr));
        animSampleClipBindposeTab->setTabText(animSampleClipBindposeTab->indexOf(animationSampleEditorWidget), QCoreApplication::translate("MainWindow", "AnimationSample Editor", nullptr));
        IsLoopingCheckBox->setText(QCoreApplication::translate("MainWindow", "Is Looping", nullptr));
        RepetitionLabel->setText(QCoreApplication::translate("MainWindow", "Repetition", nullptr));
        PlaytimeLabel->setText(QCoreApplication::translate("MainWindow", "Play Time", nullptr));
        PlayRateLabel->setText(QCoreApplication::translate("MainWindow", "PlayRate", nullptr));
        PlayPushButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        StopPushButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        ResumePushButton->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
        LoadAnimSamplePushButton->setText(QCoreApplication::translate("MainWindow", "LoadAnimSample", nullptr));
        ResetAnimSampleListPushButton->setText(QCoreApplication::translate("MainWindow", "Reset List", nullptr));
        SaveAnimationClipPushButton->setText(QCoreApplication::translate("MainWindow", "Save AnimationClip", nullptr));
        LoadAnimationClipPushButton->setText(QCoreApplication::translate("MainWindow", "Load AnimationClip", nullptr));
        animSampleClipBindposeTab->setTabText(animSampleClipBindposeTab->indexOf(animationClipEditorWidget), QCoreApplication::translate("MainWindow", "AnimationClip Editor", nullptr));
        menuAnimationTool->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
