#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "people.h"
#include "child.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <qvector.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addChild_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;//сцена
    QTimer *timer;//таймер
    QVector<People*> people;
    QVector<Child*> childs;

};
#endif // MAINWINDOW_H
