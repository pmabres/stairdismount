#pragma once
#include "../../structs/Transform.h"
#include "PhysicsTransform.h"
namespace Game
{
class PhysicsObject
{
public:
//    virtual void setTransform(PhysicsTransform& transform) = 0;
    virtual PhysicsTransform& transform() = 0;
};

}
