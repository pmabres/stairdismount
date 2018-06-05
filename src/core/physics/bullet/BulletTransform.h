#pragma once

#include <btBulletDynamicsCommon.h>
#include "../interfaces/PhysicsTransform.h"

class BulletTransform : PhysicsTransform
{
private:
    void something();
    btTransform mTransform;
};
