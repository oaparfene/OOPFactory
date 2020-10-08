#include "warehousefloor.h"

warehouseFloor::warehouseFloor(QWidget *parent) :
    QWidget(parent)
{
    timer = new QTimer(nullptr);
    timer->setInterval(30);
    connect(timer, SIGNAL(timeout()), this, SLOT(simulate()));
    instance_environment();
}

void warehouseFloor::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    paint_renderItems(p);
}

void warehouseFloor::instance_environment()
{
    for (int i = 0 ; i < 10 ; i++)
    {
        float tempx = QRandomGenerator::global()->bounded(50,1000);
        float tempy = QRandomGenerator::global()->bounded(50,1000);
        cargoItem* obj = new cargoItem(this, "box" + QString::number(i+1), tempx, tempy, 10, 10);
        itemList.append(obj);
    }


    kinematicItem* obj1 = new kinematicItem(this, "robot", 250, 250, 20, 5);

    itemList.append(obj1);

}

void warehouseFloor::paint_renderItems(QPainter &p)
{

    QVector<renderItem*>::iterator it;
    for (it = itemList.begin() ; it != itemList.end() ; it++)
    {
        (*it)->paintObject(p);
    }
}

void warehouseFloor::startSim()
{
    timer->start();
}

void warehouseFloor::simulate()
{
    QVector<renderItem*>::iterator it;
    for (it = itemList.begin() ; it != itemList.end() ; it++)
    {
        (*it)->simulate();
    }
    update();
}

void warehouseFloor::removeObject(renderItem *obj)
{
    QVector<renderItem*>::iterator it;
    for (it = itemList.begin() ; it != itemList.end() ; it++)
    {
        if ((*it)->ID == (*obj).ID)
            itemList.removeOne((*it));
    }
}

QVector2D warehouseFloor::get_nearest(QVector2D pos)
{

    QVector2D min = QVector2D(1000, 1000);
    QVector<renderItem*>::iterator it;
    for (it = itemList.begin() ; it != itemList.end() ; it++)
    {
        QVector2D temp = (*it)->getPos() - pos;
        if (temp.length() < min.length() && temp.length() != 0)
            min = temp;
    }
    return min;
}
























//endl
