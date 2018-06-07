#pragma once
#include "../../structs/Transform.h"
#include "PhysicsTransform.h"
#include "../CollisionShapes.h"
#include "../../structs/MeshTransform.h"
namespace Game
{
class PhysicsObject
{
public:
//    virtual void setTransform(PhysicsTransform& transform) = 0;
    virtual void setShape(CollisionShapes shape) = 0;
    virtual void setMass(float mass) = 0;
    virtual void setMesh(MeshTransform* meshTransform) = 0;
    virtual PhysicsTransform& transform() = 0;

};

}
