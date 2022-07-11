#include "people.h"
#include "child.h"
#include "adult.h"
#include "oldman.h"
#include "doctor.h"
#include "qgraphicsscene.h"
#include <cstdlib>

People::People()
{
    health = 100;
    isHealthy = true;
    isCarrier = false;
    isIll = false;
    isDead = false;
    isVaccinated = false;
    timeBeforeIllness = 20;
    sickTime = 80;
}

People::~People()
{

}

void People::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)


    painter->setPen(Qt::NoPen);

    painter->setBrush(QColor(Qt::gray));

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

    if(newX <= 10){
        newX += 15;

    }
    if(newX >= 750){
        newX -= 15;

    }
    if(newY <= 10){
        newY += 15;

    }
    if(newY >= 320){
        newY -= 15;

    }
    setPos(newX,newY);
}

void People::SearchForPeopleNearby(QList<QGraphicsItem *> objects)
{
    for (QGraphicsItem* someone: objects) {
        if (dynamic_cast<Child*> (someone)){
            //если рядом ребенок
            //и кто-то один не здоров, то второй становится переносчиком
            if (isHealthy == false && static_cast<Child*> (someone)->isHealthy == true){
                int random = rand() % 100 +1 ;
                if(random <= risk){
                static_cast<Child*> (someone)->isHealthy = false;
                static_cast<Child*> (someone)->isCarrier = true;
                }
            }
            //Создание группового иммунитета
            if (isVaccinated == true && (static_cast<Child*> (someone)->isHealthy == true
                                      || static_cast<Child*> (someone)->isCarrier == true)){
                static_cast<Child*> (someone)->isHealthy = true;
                static_cast<Child*> (someone)->isCarrier = false;
                static_cast<Child*> (someone)->isVaccinated = true;
                }
            }


        if (dynamic_cast<Adult*> (someone)){
            //если рядом взрослый
            //и кто-то один не здоров, то второй становится переносчиком
            if (isHealthy == false && static_cast<Adult*> (someone)->isHealthy == true){
                int random = rand() % 100 +1 ;
                if(random <= risk){
                static_cast<Adult*> (someone)->isHealthy = false;
                static_cast<Adult*> (someone)->isCarrier = true;
                }
            }
            //Создание группового иммунитета
            if (isVaccinated == true && (static_cast<Adult*> (someone)->isHealthy == true
                                      || static_cast<Adult*> (someone)->isCarrier == true)){
                static_cast<Adult*> (someone)->isHealthy = true;
                static_cast<Adult*> (someone)->isCarrier = false;
                static_cast<Adult*> (someone)->isVaccinated = true;
                }

        }
        if (dynamic_cast<OldMan*> (someone)){
            //если рядом взрослый
            //и кто-то один не здоров, то второй становится переносчиком
            if (isHealthy == false && static_cast<OldMan*> (someone)->isHealthy == true){
                int random = rand() % 100 +1 ;
                if(random <= risk){
                static_cast<OldMan*> (someone)->isHealthy = false;
                static_cast<OldMan*> (someone)->isCarrier = true;
                }
            }
            //Создание группового иммунитета
            if (isVaccinated == true && (static_cast<OldMan*> (someone)->isHealthy == true
                                      || static_cast<OldMan*> (someone)->isCarrier == true)){
                static_cast<OldMan*> (someone)->isHealthy = true;
                static_cast<OldMan*> (someone)->isCarrier = false;
                static_cast<OldMan*> (someone)->isVaccinated = true;
                }

        }

        if (dynamic_cast<Doctor*> (someone)){
            //если рядом доктор
            //и человек здоров или еще переносчик
            if (isHealthy == true || isCarrier == true){
                isHealthy = true;
                isCarrier = false;
                isVaccinated = true;
                risk = 2;
                }
            }

    }

}

void People::update()
{
    if(!isDead){
        go();
        QList<QGraphicsItem *> peopleAround = scene()->collidingItems(this);
        SearchForPeopleNearby(peopleAround);
        if(isCarrier == true){
            timeBeforeIllness--;
            if(timeBeforeIllness == 0){
                isCarrier = false;
                isIll = true;
                timeBeforeIllness = 20;
            }
        }
        if(isIll == true){
            sickTime--;
            if(sickTime == 0){
                int random = rand() % 100 + 1;
                isIll = false;

                if(random>50)
                    isDead = true;
                else
                    isHealthy = true;
                sickTime = 80;
            }
        }

    }

}
