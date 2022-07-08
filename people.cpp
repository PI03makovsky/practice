#include "people.h"
#include <cstdlib>

People::People()
{
    health = 100;
    mask = false;
    isHealthy = true;
    isCarrier = false;
    isIll = false;
}

People::~People()
{

}

void People::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)


    painter->setPen(Qt::NoPen);

    painter->setBrush(QColor(Qt::white));

    painter->drawEllipse(0,0,20,20);
}

QRectF People::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void People::go()
{
    srand(rand());
    int newX = pos().x() + (rand() % (21) - 10);
    int newY = pos().y() + (rand() % (21) - 10);
    setPos(newX,newY);
}

void People::update()
{
    if(!isDead)
        go();
}
