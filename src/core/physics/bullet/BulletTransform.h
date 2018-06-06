#pragma once

#include <btBulletDynamicsCommon.h>
#include "../interfaces/PhysicsTransform.h"

namespace Game
{
class BulletTransform: PhysicsTransform
{
public:
    BulletTransform(btTransform& transform);
    Transform fromPhysics();
private:
    btTransform& mTransform;
};
}
