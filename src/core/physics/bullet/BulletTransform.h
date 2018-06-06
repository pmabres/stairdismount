#pragma once

#include <btBulletDynamicsCommon.h>
#include "../interfaces/PhysicsTransform.h"

namespace Game
{
class BulletTransform: public PhysicsTransform
{
public:
    BulletTransform(Transform transform);
    Transform fromPhysics();
    void setTransform(Transform transform) override;
    btTransform& getNativeTransform();
private:
    btTransform mTransform;
};
}
