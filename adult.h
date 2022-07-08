#ifndef ADULT_H
#define ADULT_H

#include "people.h"

class Adult : public People
{
    Q_OBJECT
public:
    Adult();
    Adult(bool isHealthy,bool isCarrier, bool isIll);
    ~Adult();


protected:
    //Отрисовка
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr) override;
    //Прямоугольная зона объекта
    QRectF boundingRect() const override;
};

#endif // ADULT_H
