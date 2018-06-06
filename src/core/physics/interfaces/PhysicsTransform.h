
#pragma once
#include "../../structs/Transform.h"

namespace Game
{
class PhysicsTransform
{
public:
    virtual Transform fromPhysics() = 0;
};

}
