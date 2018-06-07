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
void BulletObject::setShape(CollisionShapes shape)
{
    mCollisionShape = shape;
}
void BulletObject::setMass(float mass)
{
    mMass = mass;
}
CollisionShapes BulletObject::getShape()
{
    return mCollisionShape;
}
float BulletObject::getMass()
{
    return mMass;
}
void BulletObject::setMesh(MeshTransform *meshTransform)
{
    mMeshTransform = meshTransform;
}
MeshTransform *BulletObject::getMesh()
{
    return mMeshTransform;
}
}