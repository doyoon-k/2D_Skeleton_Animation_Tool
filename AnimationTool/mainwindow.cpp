#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTreeWidget"
#include <QFileDialog>
#include "Skeleton.h"
#include "AnimationSample.h"
#include "BindPoseGenerator/skeletonhierarchytreewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bindPoseGeneratorWidget->graphicsView = ui->bindposeGraphicsView;
    ui->bindPoseGeneratorWidget->spriteListWidget = ui->spriteList;
    ui->bindPoseGeneratorWidget->skeleonHierarchyTreeWidget = ui->skeletonHierarchyTree;
    ui->bindPoseGeneratorWidget->widthPixelSpinBox = ui->widthPixelSpinBox;
    ui->bindPoseGeneratorWidget->heightPixelSpinBox = ui->heightPixelSpinBox;
    ui->bindPoseGeneratorWidget->imagesListWidget = ui->imagesList;
    ui->bindPoseGeneratorWidget->ConnectSpinboxSignals();
    ui->bindposeGraphicsView->widthPixel = ui->widthPixelSpinBox->value();
    ui->bindposeGraphicsView->heightPixel = ui->heightPixelSpinBox->value();
//    showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_closeButton_clicked()
{
   close();
}

void MainWindow::on_loadImagePushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),"/",tr("Image Files (*.png *.jpg *)"));
    ui->imagesList->addItem(fileName);
}
void MainWindow::on_spriteOpacitySlider_valueChanged(int value)
{
    ui->bindposeGraphicsView->SetSpriteGraphicsItemsOpacity(static_cast<qreal>(value)/100.0);
}

void MainWindow::on_saveBindPoseButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Set file name"),"./",tr("Animation Sample File (*.asmpl)"));
    QFile saveFile(fileName);
    if(saveFile.open(QIODevice::ReadWrite))
    {
        //스켈레톤 위젯에서 스켈레톤 인스턴스 조립한거 반환받고 스프라이트 리스트 위젯에서 스프라이트 메시 조립해서 반환받고 애님샘플에 그 두개 복사해넣고 saveAnim함수 콜해서 저장.
//        QTextStream stream(&saveFile);
        Skeleton&& skeleton = ui->bindPoseGeneratorWidget->skeleonHierarchyTreeWidget->GetSkeletonInstance(fileName);
        SpriteMesh&& spriteMesh = ui->bindPoseGeneratorWidget->spriteListWidget->GetSpriteMeshInstance(fileName,skeleton);
        AnimationSample bindPose{fileName,skeleton,spriteMesh};
//        SaveAnimSample(stream,bindPose);
    }
}
