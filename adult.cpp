#include "adult.h"

Adult::Adult()
{
    risk = 50;
}

Adult::Adult(bool isHealthy, bool isCarrier, bool isIll)
{
    this->isHealthy = isHealthy;
    this->isCarrier = isCarrier;
    this->isIll = isIll;
    risk = 50;
}

Adult::~Adult()
{

}

void Adult::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)


    painter->setPen(Qt::NoPen);

    if(isHealthy)
    painter->setBrush(QColor(Qt::white));
    else if(isCarrier)
        painter->setBrush(QColor(QColor(222,49,99)));
    else if(isIll)
        painter->setBrush(QColor(Qt::red));
    else if (isDead)
        painter->setBrush(QColor(Qt::black));

    painter->drawEllipse(0,0,20,20);
}

QRectF Adult::boundingRect() const
{
    return QRectF(0,0,20,20);
}
