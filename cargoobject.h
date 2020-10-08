#ifndef CARGOOBJECT_H
#define CARGOOBJECT_H

#include "renderobject.h"

class cargoObject : public renderObject
{
public:
    cargoObject(factoryfloor* _parent, QString _name, float _x, float _y, float _r, float _weight);
    virtual ~cargoObject() {};
    void simulate();

protected:
    float weight;
};

#endif // CARGOOBJECT_H
