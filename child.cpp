#include "child.h"

Child::Child()
{

}

Child::Child(bool isHealthy, bool isCarrier, bool isIll)
{
    this->isHealthy = isHealthy;
    this->isCarrier = isCarrier;
    this->isIll = isIll;
}

Child::~Child()
{

}

void Child::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    Q_UNUSED(option)
    Q_UNUSED(widget)


    painter->setPen(Qt::NoPen);

    if(isHealthy)
    painter->setBrush(QColor(Qt::white));
    else if(isCarrier)
        painter->setBrush(QColor(QColor(255,54,24)));
    else if(isIll)
        painter->setBrush(QColor(Qt::red));
    else if (isDead)
        painter->setBrush(QColor(Qt::black));

    painter->drawEllipse(0,0,15,15);
}

QRectF Child::boundingRect() const
{
    return QRectF(0,0,15,15);
}
