#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Подключение графической сцены
    scene = new QGraphicsScene();
    scene->setSceneRect(10,10,780,340);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsView->setScene(scene);


}

MainWindow::~MainWindow()
{
    delete ui;
}

