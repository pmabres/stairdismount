#pragma once
#include "../../structs/Transform.h"
#include "PhysicsTransform.h"
namespace Game
{
class PhysicsObject
{
public:
    virtual PhysicsTransform transform() = 0;
};

}
