#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <QString>
#include <QColor>
#include <QPainter>
#include <QVector2D>
#include <QTimer>
#include <QObject>

class factoryfloor;

class renderObject // renderBase? renderItem, Thing (avoid using the name "Object")
{
public:
    renderObject(factoryfloor* _parent, QString _name, float _x, float _y, float _r);
    virtual ~renderObject() {};
    void paintObject(QPainter &p);
    void setPos(float _x, float _y);
    virtual void simulate() = 0;
    QVector2D getPos() const; // make note: make funcs const when possible
    int ID;

protected:
    static int objectCount;
    float x,y,r; // x,y are for drawing the circles, r is radius
    QVector2D pos; //true position: center of circle
    QString name;
    QColor color;
    factoryfloor* parent;

private:

};

#endif // RENDEROBJECT_H
