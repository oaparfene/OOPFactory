#ifndef CARGOOBJECT_H
#define CARGOOBJECT_H

#include "renderitem.h"

class cargoItem : public renderItem
{
public:
    cargoItem(warehouseFloor* _parent, QString _name, float _x, float _y, float _r, float _weight);
    virtual ~cargoItem() {};
    void simulate();

protected:
    float weight;
};

#endif // CARGOOBJECT_H
