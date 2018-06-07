#pragma once
#include "../interfaces/PhysicsObject.h"
#include "BulletTransform.h"
#include "../interfaces/PhysicsTransform.h"
#include "../../structs/MeshTransform.h"
namespace Game
{
class BulletObject : public PhysicsObject
{
public:
    BulletObject(Transform transform);
    ~BulletObject();
    PhysicsTransform& transform() override;
    BulletTransform& nativeTransform();
    void setShape(CollisionShapes shape) override;
    void setMass(float mass) override;
    //Note: This shouldn't go here but added because of lack of time.
    void setMesh(MeshTransform* meshTransform) override;
    MeshTransform* getMesh();
    CollisionShapes getShape();
    float getMass();

private:
    BulletTransform mTransform;
    CollisionShapes mCollisionShape;
    float mMass;
    //Note: This shouldn't go here but added because of lack of time.
    MeshTransform* mMeshTransform;
};

}
