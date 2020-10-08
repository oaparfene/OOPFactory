#include "cargoobject.h"
#include "factoryfloor.h"

cargoObject::cargoObject(factoryfloor* _parent,QString _name, float _x, float _y, float _r, float _weight) : renderObject(_parent, _name, _x, _y, _r)
{
    weight = _weight;
    color = Qt::blue;
}

void cargoObject::simulate()
{
     QVector2D direction = parent->get_nearest(pos);
     if (direction.length() < r)
     {
         parent->removeObject(this);
     }
}
