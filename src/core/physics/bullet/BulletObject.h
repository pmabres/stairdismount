#pragma once
#include "../interfaces/PhysicsObject.h"
namespace Game
{
class BulletObject : public PhysicsObject
{
public:
    PhysicsTransform transform();
private:
    PhysicsTransform transform;
};

}
