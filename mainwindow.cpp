#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "people.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Подключение графической сцены
    scene = new QGraphicsScene();
    scene->setSceneRect(10,10,750,320);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsView->setScene(scene);

    timer = new QTimer;


    //Добавление детей
    for(int i = 0; i<10;i++){
        auto child = new Child();
        childs.push_back(child);

        childs[i]->setPos(rand() % (741) + 10
                          ,rand() % (311) + 10);

        scene->addItem(childs[i]);

        //подключить слот update
        connect(timer,SIGNAL(timeout()),childs[i],SLOT(update()));
    }

    //Добавление взрослых
    for(int i = 0; i<10;i++){
        auto newadult = new Adult();
        adults.push_back(newadult);

        adults[i]->setPos(rand() % (741) + 10
                          ,rand() % (311) + 10);

        scene->addItem(adults[i]);

        //подключить слот update
        connect(timer,SIGNAL(timeout()),adults[i],SLOT(update()));
    }

    //Добавление пожилых
    for(int i = 0; i<10;i++){
        auto newOld = new OldMan();
        oldMans.push_back(newOld);

        oldMans[i]->setPos(rand() % (741) + 10
                          ,rand() % (311) + 10);

        scene->addItem(oldMans[i]);

        //подключить слот update
        connect(timer,SIGNAL(timeout()),oldMans[i],SLOT(update()));
    }

       timer->start(500);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addChild_clicked()
{
    auto child = new Child(false,false,true);
    childs.push_back(child);

    int last = childs.size() - 1;
    childs[last]->setPos(rand() % (741) + 10
                      ,rand() % (311) + 10);

    scene->addItem(childs[last]);

    //подключить слот update
    connect(timer,SIGNAL(timeout()),childs[last],SLOT(update()));
}


void MainWindow::on_pushButton_2_clicked()
{
    auto newadult = new Adult(false,false,true);
    adults.push_back(newadult);

    int last = adults.size() - 1;
    adults[last]->setPos(rand() % (741) + 10
                      ,rand() % (311) + 10);

    scene->addItem(adults[last]);

    //подключить слот update
    connect(timer,SIGNAL(timeout()),adults[last],SLOT(update()));
}


void MainWindow::on_pushButton_3_clicked()
{
    auto newOld = new OldMan(false,false,true);;
    oldMans.push_back(newOld);

    int last = oldMans.size() - 1;
    oldMans[last]->setPos(rand() % (741) + 10
                      ,rand() % (311) + 10);

    scene->addItem(oldMans[last]);

    //подключить слот update
    connect(timer,SIGNAL(timeout()),oldMans[last],SLOT(update()));
}

