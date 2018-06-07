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
    if (!mInitialized)
    {

        mDrawModule = GameCore::get().getModule<DrawModule>();
        mCollisionConfiguration = new btDefaultCollisionConfiguration();
        mDispatcher = new btCollisionDispatcher(mCollisionConfiguration);
        mOverlappingPairCache = new btDbvtBroadphase();
        mSolver = new btSequentialImpulseConstraintSolver;
        mDynamicsWorld =
            new btDiscreteDynamicsWorld(mDispatcher, mOverlappingPairCache, mSolver, mCollisionConfiguration);
        //Earth gravity -9.81f
        mDynamicsWorld->setGravity(btVector3(0, -.4f, 0));
        mDynamicsWorld->setDebugDrawer(&mDebugDrawer);
        mDebugDrawer.setupShaders();
        mInitialized = true;
    }
}

void Bullet::start()
{
    mRunning = true;
    processObjectCreationQueue();
}
void Bullet::update()
{
    if (mRunning && mInitialized)
    {
        mDynamicsWorld->stepSimulation(GTime::getDeltaMicro() / 1000.0d / 60.0d, 10);
        auto cameraData = mDrawModule->getProjection();
        mDebugDrawer.SetMatrices(cameraData.viewMatrix, cameraData.projectionMatrix);
        mDynamicsWorld->debugDrawWorld();
        for (int j = mDynamicsWorld->getNumCollisionObjects() - 1; j >= 0; j--)
        {
            btCollisionObject *obj = mDynamicsWorld->getCollisionObjectArray()[j];
            btRigidBody *body = btRigidBody::upcast(obj);

            auto bulletObject = static_cast<BulletObject*>(body->getUserPointer());
            if (bulletObject->getMass() > 0)
            {
                btTransform trans;
                if (body && body->getMotionState()) {
                    body->getMotionState()->getWorldTransform(trans);
                }
                else {
                    trans = obj->getWorldTransform();
                }
                bulletObject->nativeTransform().setTransform(trans);
            }
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
    for (i ; i < mPhysicsQueueVector.size(); i++)
    {
        delete mPhysicsQueueVector.at(i);
    }
    mPhysicsQueueVector.clear();

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
    mPhysicsQueueVector.push_back(physicsObject);
    return physicsObject;
}

Bullet::processObjectCreationQueue()
{
    for (uint32_t i = 0; i < mPhysicsQueueVector.size(); i++)
    {
        addObjectToWorld(mPhysicsQueueVector[i]);
    }
    //This can be used for adding objects at runtime but for now lets just stay with one list that will be initialized at the beginning.
    //while( mPhysicsQueueVector.size() > 0)
    //{
        //addObjectToWorld(mPhysicsQueueVector[0]);
        //Note: Might not be performant
        //mPhysicsQueueVector.removeAtIndex(0);
    //}
}

void Bullet::addObjectToWorld(BulletObject *bulletObject)
{

    //TODO: Get shape by params.
    btCollisionShape *objectShape = generateShape(bulletObject);


    //NOTE:: HARCODED STAIRS::
    if (bulletObject->getShape() == CollisionShapes::STAIRS)
    {
        //We need to guess the stair positioning as I don't have the debug drawer yet =(.
        auto originalTransform = bulletObject->nativeTransform().getNativeTransform();
        auto originalX = originalTransform.getOrigin().getX();
        auto originalY = originalTransform.getOrigin().getY();
        auto originalZ = originalTransform.getOrigin().getZ();
        auto planeUp1 = new btStaticPlaneShape(btVector3(0,1,0),1);
        auto planeTransform = new btTransform();
        planeTransform->setOrigin(btVector3(originalX,originalY,originalZ) + btVector3(-4,-10,0));
        planeTransform->setIdentity();
        auto planeUp2 = new btStaticPlaneShape(btVector3(0,1,0),1);
        auto planeTransform2 = new btTransform();
        planeTransform2->setOrigin(btVector3(originalX,originalY,originalZ) + btVector3(-4,-10,0));
        planeTransform2->setIdentity();
        auto planeUp3 = new btStaticPlaneShape(btVector3(0,1,0),1);
        auto planeTransform3 = new btTransform();
        planeTransform3->setOrigin(btVector3(originalX,originalY,originalZ) + btVector3(-4,-10,0));
        planeTransform3->setIdentity();
        auto planeUp4 = new btStaticPlaneShape(btVector3(0,1,0),1);
        auto planeTransform4 = new btTransform();
        planeTransform4->setOrigin(btVector3(originalX,originalY,originalZ) + btVector3(-4,-10,0));
        planeTransform4->setIdentity();
        auto planeLeft1 = new btStaticPlaneShape(btVector3(-1,0,0),1);
        auto planeTransformL1 = new btTransform();
        planeTransformL1->setOrigin(btVector3(originalX,originalY,originalZ) + btVector3(-4,-10,0));
        planeTransformL1->setIdentity();
        auto planeLeft2 = new btStaticPlaneShape(btVector3(-1,0,0),1);
        auto planeTransformL2 = new btTransform();
        planeTransformL2->setOrigin(btVector3(originalX,originalY,originalZ) + btVector3(-4,-10,0));
        planeTransformL2->setIdentity();
        auto planeLeft3 = new btStaticPlaneShape(btVector3(-1,0,0),1);
        auto planeTransformL3 = new btTransform();
        planeTransformL3->setOrigin(btVector3(originalX,originalY,originalZ) + btVector3(-4,-10,0));
        planeTransformL3->setIdentity();
        auto planes = std::vector<std::pair<btStaticPlaneShape*, btTransform*>>();
        planes.reserve(7);
        planes.push_back(std::pair<btStaticPlaneShape*, btTransform*> (planeUp1, planeTransform));
        planes.push_back(std::pair<btStaticPlaneShape*, btTransform*> (planeUp2, planeTransform2));
        planes.push_back(std::pair<btStaticPlaneShape*, btTransform*> (planeUp3, planeTransform3));
        planes.push_back(std::pair<btStaticPlaneShape*, btTransform*> (planeUp4, planeTransform4));
        planes.push_back(std::pair<btStaticPlaneShape*, btTransform*> (planeLeft1, planeTransformL1));
        planes.push_back(std::pair<btStaticPlaneShape*, btTransform*> (planeLeft2, planeTransformL2));
        planes.push_back(std::pair<btStaticPlaneShape*, btTransform*> (planeLeft3, planeTransformL3));

        for (auto shape : planes)
        {
            auto plane = shape.first;
            auto transform = shape.second;
            mCollisionShapes.push_back(plane);
            //get mass as params
            btScalar mass(bulletObject->getMass());

            //rigidbody is dynamic if and only if mass is non zero, otherwise static
            bool isDynamic = (mass != 0.f);

            btVector3 localInertia(0, 0, 0);
            if (isDynamic)
                plane->calculateLocalInertia(mass, localInertia);

            //using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
            auto myMotionState = new btDefaultMotionState(*transform);
            btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, plane, localInertia);
            auto body = new btRigidBody(rbInfo);
            body->setUserPointer(bulletObject);
            //add the body to the dynamics world
            mDynamicsWorld->addRigidBody(body);
        }

        return;
    }




    mCollisionShapes.push_back(objectShape);

    //get mass as params
    btScalar mass(bulletObject->getMass());

    //rigidbody is dynamic if and only if mass is non zero, otherwise static
    bool isDynamic = (mass != 0.f);

    btVector3 localInertia(0, 0, 0);
    if (isDynamic)
        objectShape->calculateLocalInertia(mass, localInertia);

    //using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
    auto myMotionState = new btDefaultMotionState(bulletObject->nativeTransform().getNativeTransform());
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, objectShape, localInertia);
    auto body = new btRigidBody(rbInfo);
    body->setUserPointer(bulletObject);
    //add the body to the dynamics world
    mDynamicsWorld->addRigidBody(body);
}

btCollisionShape *Bullet::generateShape(BulletObject* bulletObject)
{
    btCollisionShape* collisionShape;
    CollisionShapes shapes = bulletObject->getShape();
    //TODO: Instead of this case I was hoping to create each class of shapes. so we have a reusable way of interacting with shapes.
    switch(shapes)
    {
    //TODO: FIX THE MESH COLLIDER;
    case CollisionShapes::MESH:
        {
            btTriangleMesh triangleMesh = new btTriangleMesh();
            auto itVertex = bulletObject->getMesh()->vertices.begin();
            //Note: Im assuming that the vertex come already triangulated in order (1,2,3:1,2,3:...) but this might be breaking the collision shape.
            while (itVertex != bulletObject->getMesh()->vertices.end())
            {
                auto vertex1 = btVector3(itVertex->x, itVertex->y, itVertex->z);
                itVertex++;
                auto vertex2 = btVector3(itVertex->x, itVertex->y, itVertex->z);
                itVertex++;
                auto vertex3 = btVector3(itVertex->x, itVertex->y, itVertex->z);
                triangleMesh.addTriangle(vertex1, vertex2, vertex3);
                itVertex++;
            }
            auto itIndices = bulletObject->getMesh()->indices.begin();
            while (itIndices != bulletObject->getMesh()->indices.end())
            {
                triangleMesh.addIndex(*itIndices);
                itIndices++;
            }
            collisionShape = new btBvhTriangleMeshShape(&triangleMesh, true);
        }
        break;
    case CollisionShapes::BOX:
        {
            collisionShape = new btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));
        }
        break;
    case CollisionShapes::SPHERE:
        //TODO: Replace the sphere for the proper ragdoll.
        {
            collisionShape = new btSphereShape(1);
        }
        break;
    case CollisionShapes::RAGDOLL:
        //TODO: Replace the sphere for the proper ragdoll.
        {
            collisionShape = new btSphereShape(5);
        }
        break;
    }
    return collisionShape;
}

}

