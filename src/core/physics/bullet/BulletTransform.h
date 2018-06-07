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
    void setTransform(const btTransform& transform);

    btTransform& getNativeTransform();
private:
    btTransform mTransform;
};
}
