
#pragma once
#include "../../structs/Transform.h"

namespace Game
{
class PhysicsTransform
{
public:
    virtual Transform fromPhysics() = 0;
    virtual void setTransform(Transform transform) = 0;
};

}
