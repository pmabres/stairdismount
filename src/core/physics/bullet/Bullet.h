#pragma once

#include "../interfaces/PhysicsEngine.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

class Bullet final : public PhysicsEngine
{
public:
    Bullet();
    ~Bullet();
    void configure();
    void start();
    void update();
    void stop();
    void destroy();
    void test();
private:
    btDefaultCollisionConfiguration* mCollisionConfiguration;
    btCollisionDispatcher* mDispatcher;
    btBroadphaseInterface* mOverlappingPairCache;
    btSequentialImpulseConstraintSolver* mSolver;
    btDiscreteDynamicsWorld* mDynamicsWorld;
    btAlignedObjectArray<btCollisionShape*> mCollisionShapes;
    std::atomic_bool mRunning;
    std::atomic_bool mInitialized;

};
