#ifndef KINEMATICOBJECT_H
#define KINEMATICOBJECT_H

#include "renderobject.h"

class kinematicObject : public renderObject
{
public:
    kinematicObject(factoryfloor* _parent, QString _name, float _x, float _y, float _r, float _vel);
    virtual ~kinematicObject() {};
    void simulate();

private:
    //QVector2D get_nearest_cargo();
    void move_to_nearest();
    float vel;
};

#endif // KINEMATICOBJECT_H
