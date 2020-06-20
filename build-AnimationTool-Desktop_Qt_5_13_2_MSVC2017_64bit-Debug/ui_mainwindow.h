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
#include <QtWidgets/QGridLayout>
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
#include <QtWidgets/QWidget>
#include "BindPoseGenerator/bindposeanimsamplegenerator.h"
#include "BindPoseGenerator/bindposeanimsamplegeneratorgraphicsview.h"
#include "BindPoseGenerator/skeletonhierarchytreewidget.h"
#include "BindPoseGenerator/spritelistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *animSampleClipBindposeTab;
    QWidget *animationSampleEditorWidget;
    QWidget *animationClipEditorWidget;
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
    QPushButton *closeButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAnimationTool;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 620);
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
        animSampleClipBindposeTab = new QTabWidget(centralwidget);
        animSampleClipBindposeTab->setObjectName(QString::fromUtf8("animSampleClipBindposeTab"));
        animationSampleEditorWidget = new QWidget();
        animationSampleEditorWidget->setObjectName(QString::fromUtf8("animationSampleEditorWidget"));
        animSampleClipBindposeTab->addTab(animationSampleEditorWidget, QString());
        animationClipEditorWidget = new QWidget();
        animationClipEditorWidget->setObjectName(QString::fromUtf8("animationClipEditorWidget"));
        animSampleClipBindposeTab->addTab(animationClipEditorWidget, QString());
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
        bindposeGraphicsView->setMinimumSize(QSize(600, 400));
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

        gridLayout->addWidget(animSampleClipBindposeTab, 4, 0, 1, 1);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMaximumSize(QSize(100, 100));

        gridLayout->addWidget(closeButton, 2, 0, 1, 1);

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
        animSampleClipBindposeTab->setTabText(animSampleClipBindposeTab->indexOf(animationSampleEditorWidget), QCoreApplication::translate("MainWindow", "AnimationSample Editor", nullptr));
        animSampleClipBindposeTab->setTabText(animSampleClipBindposeTab->indexOf(animationClipEditorWidget), QCoreApplication::translate("MainWindow", "AnimationClip Editor", nullptr));
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
        closeButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        menuAnimationTool->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
