#include "BulletObject.h"
#include "BulletTransform.h"

namespace Game
{
BulletObject::BulletObject(Transform transform) : mTransform(transform)
{
}
BulletObject::~BulletObject()
{
}
PhysicsTransform& BulletObject::transform(){
    return mTransform;
}
BulletTransform& BulletObject::nativeTransform()
{
    return mTransform;
}
}