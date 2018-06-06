#pragma once
#include "GrObject.h"
#include "GrLinkerObject.h"
#include "BulletCollision/CollisionShapes/btCollisionShape.h"
#include "btBulletDynamicsCommon.h"

class GrBulletObject :
    public GrObject
{
private:
    Vector startOrigin;
    Vector startRotationAxis;
    double startRotationAngle;
    GrLinkerObject *linker;

    virtual void updateOrigin();
    virtual void updateRotation();
public:
    GrBulletObject();
    GrBulletObject(btRigidBody *rigidBody);
    ~GrBulletObject();
    virtual void draw();
    virtual void update();
    void resetPosition();
    void activate();
    void setLinker(GrLinkerObject *linker);
    btRigidBody *rigidBody;
    btRigidBody *getRigidBody();
};
