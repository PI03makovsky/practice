#ifndef DOCTOR_H
#define DOCTOR_H


#include "people.h"

class Doctor : public People
{
    Q_OBJECT
public:
    Doctor();
    ~Doctor();
protected:
    //Отрисовка
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr) override;
    //Прямоугольная зона объекта
    QRectF boundingRect() const override;
};

#endif // DOCTOR_H
