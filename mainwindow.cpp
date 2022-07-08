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

    //Добавление людей
       for(int i = 0; i<5;i++){
       auto man = new People();
       people.push_back(man);

       people[i]->setPos(rand() % (741) + 10
                       ,rand() % (311) + 10);

       scene->addItem(people[i]);

       //подключить слот update
       connect(timer,SIGNAL(timeout()),people[i],SLOT(update()));
       }

       //Добавление детей
          for(int i = 0; i<5;i++){
          auto child = new Child();
          childs.push_back(child);

          childs[i]->setPos(rand() % (741) + 10
                          ,rand() % (311) + 10);

          scene->addItem(childs[i]);

          //подключить слот update
          connect(timer,SIGNAL(timeout()),childs[i],SLOT(update()));
          }

       timer->start(500);


}

MainWindow::~MainWindow()
{
    delete ui;
}

