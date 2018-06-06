#pragma once

#include "../interfaces/PhysicsEngine.h"
#include "BulletObject.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <atomic>

namespace Game
{
class Bullet : public PhysicsEngine
{
public:
    Bullet();
    ~Bullet();
    void configure() override;
    void start() override;
    void update() override;
    void stop() override;
    void destroy() override;
    PhysicsObject* createObject(Transform transform) override;

private:
    void addObjectToWorld(BulletObject* bulletObject);
    btDefaultCollisionConfiguration *mCollisionConfiguration;
    btCollisionDispatcher *mDispatcher;
    btBroadphaseInterface *mOverlappingPairCache;
    btSequentialImpulseConstraintSolver *mSolver;
    btDiscreteDynamicsWorld *mDynamicsWorld;
    btAlignedObjectArray<btCollisionShape *> mCollisionShapes;
    btAlignedObjectArray<PhysicsObject *> mPhysicsObjectVector;
    std::atomic_bool mRunning;
    std::atomic_bool mInitialized;

};

}
