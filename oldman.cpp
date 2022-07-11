#include "oldman.h"

OldMan::OldMan()
{
    risk = 80;
}

OldMan::OldMan(bool isHealthy, bool isCarrier, bool isIll)
{
    this->isHealthy = isHealthy;
    this->isCarrier = isCarrier;
    this->isIll = isIll;
    risk = 80;
}

OldMan::~OldMan()
{

}

void OldMan::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)


    painter->setPen(Qt::NoPen);

    if(isVaccinated)
         painter->setBrush(QColor(Qt::green));
    else if(isHealthy)
    painter->setBrush(QColor(Qt::white));
    else if(isCarrier)
        painter->setBrush(QColor(QColor(222,49,99)));
    else if(isIll)
        painter->setBrush(QColor(Qt::red));
    else if (isDead)
        painter->setBrush(QColor(Qt::black));

    painter->drawRect(0,0,18,18);

}


QRectF OldMan::boundingRect() const
{
    return QRectF(0,0,18,18);
}
