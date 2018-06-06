//
// Created by pancho on 04-Jun-18.
//

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
BulletTransform::BulletTransform(btTransform& transform): mTransform(transform)
{

}
}
