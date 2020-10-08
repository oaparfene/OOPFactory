#include "renderobject.h"

int renderObject::objectCount = 1;

renderObject::renderObject(factoryfloor *_parent, QString _name, float _x, float _y, float _r)
{

    parent = _parent;
    ID = objectCount++;
    name = _name;
    x = _x;
    y = _y;
    pos = QVector2D(_x+_r,_y+_r);
    r = _r;
    color = Qt::gray;
}

void renderObject::paintObject(QPainter &p)
{
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);
    p.drawEllipse(QRect(x, y, 2*r, 2*r));

    p.drawText(pos.x(),pos.y(),QString::number(ID));
}

void renderObject::setPos(float _x, float _y)
{
    x = _x;
    y = _y;
    pos.setX(x+r);
    pos.setY(y+r);
}

QVector2D renderObject::getPos() const
{
    return pos;
}
