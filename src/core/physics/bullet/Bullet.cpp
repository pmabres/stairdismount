#include "Bullet.h"
#include "../../GameCore.h"
#include "BulletObject.h"

namespace Game
{
Bullet::Bullet()
    :
    mInitialized(false),
    mRunning(false)
{

}
Bullet::~Bullet()
{
    destroy();
}
void Bullet::configure()
{
    if (!mInitialized) {

        mCollisionConfiguration = new btDefaultCollisionConfiguration();
        mDispatcher = new btCollisionDispatcher(mCollisionConfiguration);
        mOverlappingPairCache = new btDbvtBroadphase();
        mSolver = new btSequentialImpulseConstraintSolver;
        mDynamicsWorld =
            new btDiscreteDynamicsWorld(mDispatcher, mOverlappingPairCache, mSolver, mCollisionConfiguration);
        mDynamicsWorld->setGravity(btVector3(0, -9.81f, 0));
        mInitialized = true;

//
//        {
//            btCollisionShape *ground = new btStaticPlaneShape(btVector3(0, 1, 0), 1);
//
//            btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0,0,0)));
//
//            btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0, groundMotionState, ground, btVector3(0, 0, 0));
//
//            btRigidBody *groundRigidBody = new btRigidBody(groundRigidBodyCI);
//
//            world->addRigidBody(groundRigidBody);
//        }
    }
}
void Bullet::addObjectToWorld(BulletObject *bulletObject)
{

    //TODO: Get shape by params.
    btCollisionShape *objectShape = new btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));

    mCollisionShapes.push_back(objectShape);

    //get mass as params
    btScalar mass(0.f);

    //rigidbody is dynamic if and only if mass is non zero, otherwise static
    bool isDynamic = (mass != 0.f);

    btVector3 localInertia(0, 0, 0);
    if (isDynamic)
        objectShape->calculateLocalInertia(mass, localInertia);

    //using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
    auto myMotionState = new btDefaultMotionState(bulletObject->nativeTransform().getNativeTransform());
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, objectShape, localInertia);
    auto body = new btRigidBody(rbInfo);

    //add the body to the dynamics world
    mDynamicsWorld->addRigidBody(body);
}

void Bullet::start()
{
    mRunning = true;
}
void Bullet::update()
{
    if (mRunning && mInitialized) {
        mDynamicsWorld->stepSimulation(1.f / 60.f, 10);
        for (int j = mDynamicsWorld->getNumCollisionObjects() - 1; j >= 0; j--) {
            btCollisionObject *obj = mDynamicsWorld->getCollisionObjectArray()[j];
            btRigidBody *body = btRigidBody::upcast(obj);
            btTransform trans;
            if (body && body->getMotionState()) {
                body->getMotionState()->getWorldTransform(trans);
            }
            else {
                trans = obj->getWorldTransform();
            }
            //printf("world pos object %d = %f,%f,%f\n", j, float(trans.getOrigin().getX()), float(trans.getOrigin().getY()), float(trans.getOrigin().getZ()));
        }
    }

}
void Bullet::stop()
{
    mRunning = false;
}

void Bullet::destroy()
{
    auto i = 0;
    for (i ; i < mPhysicsObjectVector.size(); i++)
    {
        delete mPhysicsObjectVector.at(i);
    }
    mPhysicsObjectVector.clear();

    if (mInitialized) {
        for (i = mDynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--) {
            btCollisionObject *obj = mDynamicsWorld->getCollisionObjectArray()[i];
            btRigidBody *body = btRigidBody::upcast(obj);
            if (body && body->getMotionState()) {
                delete body->getMotionState();
            }
            mDynamicsWorld->removeCollisionObject(obj);
            delete obj;
        }

        for (int j = 0; j < mCollisionShapes.size(); j++) {
            btCollisionShape *shape = mCollisionShapes[j];
            mCollisionShapes[j] = 0;
            delete shape;
        }

        delete mDynamicsWorld;
        delete mSolver;
        delete mOverlappingPairCache;
        delete mDispatcher;
        delete mCollisionConfiguration;
        mCollisionShapes.clear();
        mInitialized = false;
    }
}

PhysicsObject* Bullet::createObject(Transform transform)
{
    auto physicsObject = new BulletObject(transform);
    mPhysicsObjectVector.push_back(physicsObject);
    addObjectToWorld(physicsObject);
    return physicsObject;
}

}

