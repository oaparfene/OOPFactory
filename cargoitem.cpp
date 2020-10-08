#include "cargoitem.h"
#include "factoryfloor.h"

cargoItem::cargoItem(factoryfloor* _parent,QString _name, float _x, float _y, float _r, float _weight) : renderItem(_parent, _name, _x, _y, _r)
{
    weight = _weight;
    color = Qt::blue;
}

void cargoItem::simulate()
{
     QVector2D direction = parent->get_nearest(pos);
     if (direction.length() < r)
     {
         parent->removeObject(this);
     }
}
