#include "../interfaces/PhysicsEngine.h"

#ifndef GAME_BULLET_H
#define GAME_BULLET_H


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

private:
    btDefaultCollisionConfiguration* mCollisionConfiguration;
    btCollisionDispatcher* mDispatcher;
    btBroadphaseInterface* mOverlappingPairCache;
    btSequentialImpulseConstraintSolver* mSolver;
    btDiscreteDynamicsWorld* mDynamicsWorld;
    btAlignedObjectArray<btCollisionShape*> mCollisionShapes;

};


#endif //GAME_BULLET_H
