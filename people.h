#ifndef PEOPLE_H
#define PEOPLE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>

class People : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    People();
    ~People();
    int health;//Здоровье
    int risk;//вероятность заразиться

    bool mask;//Наличие маски
    bool isVaccinated;//Вакцинация

    int timeBeforeIllness;//Время инкубационного периода
    int sickTime;//Время болезни
    bool isHealthy;//Здоров
    bool isCarrier;//Переносчик
    bool isIll;//Заболел
    bool isDead;//Умер
    void go();//Идти

    /*Обнаружение объектов рядом*/
    void SearchForPeopleNearby(QList<QGraphicsItem *> objects);
public slots:
    void update();//Обновить
protected:
    //Отрисовка
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr) override;
    //Прямоугольная зона объекта
    QRectF boundingRect() const override;

};

#endif // PEOPLE_H
