#include "doctor.h"

Doctor::Doctor()
{
    isVaccinated = true;
}

Doctor::~Doctor()
{

}

void Doctor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    QPolygon polygon;   // Используем класс полигона, чтобы отрисовать треугольник
    // Помещаем координаты точек в полигональную модель
    polygon << QPoint(0,-10) << QPoint(10,10) << QPoint(-10,10);

    painter->setBrush(QColor(31,117,254));     // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);  // Рисуем треугольник по полигональной модели

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Doctor::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}
