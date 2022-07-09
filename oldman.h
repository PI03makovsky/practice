#ifndef OLDMAN_H
#define OLDMAN_H

#include "people.h"

class OldMan : public People
{
    Q_OBJECT
public:
    OldMan();
    OldMan(bool isHealthy,bool isCarrier, bool isIll);
    ~OldMan();
protected:
    //Отрисовка
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr) override;
    //Прямоугольная зона объекта
    QRectF boundingRect() const override;
};

#endif // OLDMAN_H
