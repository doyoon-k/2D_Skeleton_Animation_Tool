#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTreeWidget"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bindPoseGeneratorWidget->graphicsView = ui->bindposeGraphicsView;
    ui->bindPoseGeneratorWidget->spriteListWidget = ui->spriteList;
    ui->bindPoseGeneratorWidget->skeleonHierarchyTreeWidget;
}

MainWindow::~MainWindow()
{
    delete ui;
}

