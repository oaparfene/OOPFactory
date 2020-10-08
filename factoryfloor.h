#ifndef FACTORYFLOOR_H
#define FACTORYFLOOR_H

#include <QDebug>
#include <QColor>
#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QRandomGenerator>
#include "kinematicitem.h"
#include "cargoitem.h"


class factoryfloor : public QWidget
{

    Q_OBJECT
public:
    factoryfloor(QWidget *parent = 0);
    virtual ~factoryfloor() {};
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
