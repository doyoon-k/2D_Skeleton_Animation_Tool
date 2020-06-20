#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTreeWidget"
#include <QFileDialog>
#include "Skeleton.h"
#include <QTextStream>
#include "AnimationSample.h"
#include "BindPoseGenerator/skeletonhierarchytreewidget.h"
#include <QDebug>
#include <QMessageBox>

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

    QFile imagePathList("ImagePaths.txt");
    if(imagePathList.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream stream(&imagePathList);
        while(!stream.atEnd())
        {
            QString imagePath;
            ui->imagesList->addItem(imagePath);
        }
    }

    QFile namePathPairsFile("SpriteNamePathPairs.txt");
    namePathPairsFile.open(QIODevice::ReadOnly|QIODevice::Text);

    if(namePathPairsFile.isOpen())
    {
        QTextStream stream(&namePathPairsFile);
        while(!stream.atEnd())
        {
            QString spriteName;
            QString imagePath;
            stream>>spriteName;
            stream>>imagePath;
            spriteNamePathPairs.insert(spriteName,imagePath);
            ui->imagesList->addItem(imagePath);
        }
    }
    else
    {
        qDebug()<<"SpriteName-Path Pair file does not exists!"<<endl;
    }
//    showFullScreen();
}

MainWindow::~MainWindow()
{
    QFile imagePathList("ImagePaths.txt");
    QSet<QString> paths;
    if(imagePathList.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream stream(&imagePathList);
        while(!stream.atEnd())
        {
            QString imagePath;
            stream>>imagePath;
            paths.insert(imagePath);
        }
    }
    else
    {
        QMessageBox msg;
        msg.setText("Failed to open ImagePath file!");
        msg.exec();
        return;
    }

    QFile newImagePathList("ImagePaths.txt");
    if(newImagePathList.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text))
    {
        for(int i = 0; i < ui->spriteList->count(); i++)
        {
            paths.insert(ui->spriteList->item(i)->text());
        }
    }
    else
    {
        QMessageBox msg;
        msg.setText("Failed to open ImagePath file!");
        msg.exec();
        return;
    }

    delete ui;
}

QString MainWindow::GetImagePathBySpriteName(QString imageName)
{
    return spriteNamePathPairs[imageName];
}

void MainWindow::AddSpriteNamePathPair(QString spriteName, QString path)
{
    spriteNamePathPairs[spriteName] = path;
}

void MainWindow::RemoveSpriteNamePathPair(QString spriteName)
{
    spriteNamePathPairs.remove(spriteName);
}


void MainWindow::on_closeButton_clicked()
{
   close();
}

void MainWindow::on_loadImagePushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),"./",tr("Image Files (*.png *.jpg *)"));
    ui->imagesList->addItem(fileName);
}
void MainWindow::on_spriteOpacitySlider_valueChanged(int value)
{
    ui->bindposeGraphicsView->SetSpriteGraphicsItemsOpacity(static_cast<qreal>(value)/100.0);
}

void MainWindow::on_saveBindPoseButton_clicked()
{
    //open file and store the pairs in a map
    QFile prevNamePathPairsFile("SpriteNamePathPairs.txt");
    QFileInfo info(prevNamePathPairsFile);
    if(!info.exists())
    {
        QMessageBox msgBox;
        msgBox.setText("SpriteName - ImagePath pair file does not exist!");
        msgBox.exec();
        return;
    }

    QMap<QString,QString> prevPairsFromFile;
    if(prevNamePathPairsFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream stream(&prevNamePathPairsFile);
        while(!stream.atEnd())
        {
            QString spriteName;
            QString imagePath;
            stream>>spriteName;
            stream>>imagePath;
            prevPairsFromFile.insert(spriteName,imagePath);
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Failed to open SpriteName - ImagePath pair file!");
        msgBox.exec();
        return;
    }

    //add new pairs to map
    for(auto it = spriteNamePathPairs.begin(); it != spriteNamePathPairs.end(); it++)
    {
        QString spriteName;
        QString imagePath;
        spriteName = it.key();
        imagePath = it.value();
        prevPairsFromFile[spriteName] = imagePath;
    }

    //rewrite file
    QFile newNamePathPairsFile("SpriteNamePathPairs.txt");
    newNamePathPairsFile.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text);
    if(!newNamePathPairsFile.isOpen())
    {
        QMessageBox msgBox;
        msgBox.setText("Failed to reset SpriteNamePathPairs for some reason...");
        msgBox.exec();
        return;
    }
    QTextStream stream(&newNamePathPairsFile);
    for(auto it = spriteNamePathPairs.begin(); it != spriteNamePathPairs.end(); it++)
    {
       stream<<it.key();
       stream<<it.value();
    }

    if(ui->skeletonHierarchyTree->topLevelItemCount() != 1)
    {
        QMessageBox msgBox;
        msgBox.setText("There must be only/At least one Root Joint in the hierarchy!");
        msgBox.exec();
        return;
    }
    QString fileName = QFileInfo(QFileDialog::getSaveFileName(this,tr("Set file name"),"./",tr("Animation Sample File (*.asmpl)"))).baseName();
    QFile saveFile(fileName+".asmpl");
    if(saveFile.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        //스켈레톤 위젯에서 스켈레톤 인스턴스 조립한거 반환받고 스프라이트 리스트 위젯에서 스프라이트 메시 조립해서 반환받고 애님샘플에 그 두개 복사해넣고 saveAnim함수 콜해서 저장.
        QTextStream stream(&saveFile);
        Skeleton&& skeleton = ui->bindPoseGeneratorWidget->skeleonHierarchyTreeWidget->GetSkeletonInstance(fileName);
        SpriteMesh&& spriteMesh = ui->bindPoseGeneratorWidget->spriteListWidget->GetSpriteMeshInstance(fileName,skeleton);
        AnimationSample bindPose{fileName,skeleton,spriteMesh};
        SaveAnimSample(stream,bindPose);
    }
}

void MainWindow::on_loadBindPoseButton_clicked()
{
    QFile namePathPairsFile("SpriteNamePathPairs.txt");
    QFileInfo info(namePathPairsFile);
    if(!info.exists())
    {
        QMessageBox msgBox;
        msgBox.setText("SpriteName - ImagePath pair file does not exist!");
        msgBox.exec();
        return;
    }

    QString filePath = QFileDialog::getOpenFileName(this,tr("Open BindPose"),"./",tr("AnimSample file (*.asmpl)"));
    QString fileName = QFileInfo(filePath).baseName();
    QFile saveFile(filePath);
    if(saveFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream stream(&filePath);
        AnimationSample bindPose{fileName,Skeleton(fileName+"Skeleton"),SpriteMesh()};
        LoadAnimSample(stream,bindPose);
        ui->skeletonHierarchyTree->LoadFromSkeleton(bindPose.skeleton);
        ui->spriteList->LoadFromSpriteMesh(bindPose.spriteMesh,bindPose.skeleton);
    }
}
