#include "kinematicobject.h"
#include "factoryfloor.h"

kinematicObject::kinematicObject(factoryfloor* _parent, QString _name, float _x, float _y, float _r, float _vel) : renderObject(_parent, _name, _x, _y, _r)
{
    vel = _vel;
    color = Qt::red;
}

void kinematicObject::simulate()
{

    move_to_nearest();
}

void kinematicObject::move_to_nearest()
{
    QVector2D direction = parent->get_nearest(pos);
    pos += direction.normalized() * vel;
    x += direction.normalized().x() * vel;
    y += direction.normalized().y() * vel;
}
