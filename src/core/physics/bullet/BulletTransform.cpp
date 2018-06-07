#include <iostream>
#include "BulletTransform.h"

namespace Game
{
Transform BulletTransform::fromPhysics()
{
    Transform transform;

    transform.position.x = mTransform.getOrigin().x();
    transform.position.y = mTransform.getOrigin().y();
    transform.position.z = mTransform.getOrigin().z();
    return transform;
}
BulletTransform::BulletTransform(Transform transform) : mTransform()
{
    mTransform.setIdentity();
    setTransform(transform);
}
void BulletTransform::setTransform(Transform transform)
{
    mTransform.setOrigin(btVector3(transform.position.x, transform.position.y, transform.position.z));
}
btTransform& BulletTransform::getNativeTransform()
{
    return mTransform;
}
void BulletTransform::setTransform(const btTransform &transform)
{
    mTransform = transform;
}
}
