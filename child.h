#ifndef CHILD_H
#define CHILD_H

#include "people.h"

class Child : public People
{
    Q_OBJECT
public:
    Child();
    Child(bool isHealthy,bool isCarrier, bool isIll);
    ~Child();
protected:
    //Отрисовка
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr) override;
    //Прямоугольная зона объекта
    QRectF boundingRect() const override;
};

#endif // CHILD_H
