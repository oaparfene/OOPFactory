#ifndef FACTORYFLOOR_H
#define FACTORYFLOOR_H

#include <QDebug>
#include <QColor>
#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QRandomGenerator>
#include "kinematicobject.h"
#include "cargoobject.h"


class factoryfloor : public QWidget
{

    Q_OBJECT
public:
    factoryfloor(QWidget *parent = 0);
    virtual ~factoryfloor() {};
    virtual void paintEvent(QPaintEvent *event);
    void startSim();
    QVector2D get_nearest(QVector2D pos);
    void removeObject(renderObject* obj);

private slots:
    void simulate();

private:
    QVector<renderObject*> objectList;
    void instance_environment();
    void paint_renderObjects(QPainter &p);
    QTimer* timer;
};

#endif // FACTORYFLOOR_H
