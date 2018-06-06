#pragma once

#include <btBulletDynamicsCommon.h>
#include "../interfaces/PhysicsTransform.h"

namespace Game
{
class BulletTransform: PhysicsTransform
{
private:
    void something();
    btTransform mTransform;
};
}
