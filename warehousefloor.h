#ifndef WAREHOUSEFLOOR_H
#define WAREHOUSEFLOOR_H

#include <QDebug>
#include <QColor>
#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QRandomGenerator>
#include "kinematicitem.h"
#include "cargoitem.h"


class warehouseFloor : public QWidget
{

    Q_OBJECT
public:
    warehouseFloor(QWidget *parent = 0);
    virtual ~warehouseFloor() {};
    virtual void paintEvent(QPaintEvent *event);
    void startSim();
    QVector2D get_nearest(QVector2D pos);
    void removeObject(renderItem* obj);

private slots:
    void simulate();

private:
    QVector<renderItem*> itemList;
    void instance_environment();
    void paint_renderItems(QPainter &p);
    QTimer* timer;
};

#endif // FACTORYFLOOR_H
