#pragma once
#include "../interfaces/PhysicsObject.h"
#include "BulletTransform.h"
#include "../interfaces/PhysicsTransform.h"
namespace Game
{
class BulletObject : public PhysicsObject
{
public:
    BulletObject(Transform transform);
    ~BulletObject();
    PhysicsTransform& transform() override;
    BulletTransform& nativeTransform();

private:
    BulletTransform mTransform;
};

}
