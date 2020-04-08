#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTreeWidget"
#include <QFileDialog>

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
    QFileDialog dialog(this);
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),"/",tr("Image Files (*.png *.jpg *)"));
    ui->imagesList->addItem(fileName);
}
