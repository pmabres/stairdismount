
#include "PhysicsManager.h"

namespace Game
{
void PhysicsManager::createEngine(PhysicsEngines engine)
{
    deleteEngine();
    switch (engine) {
    case PhysicsEngines::Bullet:mEngine = new Bullet();
        break;
    }

}

void PhysicsManager::deleteEngine()
{
    if (mEngine != NULL) {
        mEngine->destroy();
        delete mEngine;
    }
}

PhysicsManager::PhysicsManager() : mEngine(nullptr)
{
}

PhysicsManager::~PhysicsManager()
{
    deleteEngine();
}

void PhysicsManager::configure()
{
    if (mEngine != NULL) {
        mEngine->configure();
    }
}

void PhysicsManager::start()
{
    if (mEngine != NULL) {
        mEngine->start();
    }
}

void PhysicsManager::stop()
{
    if (mEngine != NULL) {
        mEngine->stop();
    }
}

void PhysicsManager::update()
{
    if (mEngine != NULL) {
        mEngine->update();
    }
}
PhysicsObject* PhysicsManager::createObject(Transform transform)
{
    return mEngine->createObject(transform);
}
}
