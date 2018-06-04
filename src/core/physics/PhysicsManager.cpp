
#include "PhysicsManager.h"

void PhysicsManager::createEngine(Engines engine)
{
    deleteEngine();
    switch(engine)
    {
        case Engines::Bullet:
            mEngine = new Bullet();
            break;
    }

}

void PhysicsManager::deleteEngine()
{
    if (mEngine != NULL)
    {
        mEngine.destroy();
        delete mEngine;
    }
}

void PhysicsManager::PhysicsManager()
{
}

void PhysicsManager::~PhysicsManager()
{
    deleteEngine();
}

void PhysicsManager::configure()
{
    if (mEngine != NULL)
    {
        mEngine.configure();
    }
}

void PhysicsManager::start()
{
    if (mEngine != NULL)
    {
        mEngine.start();
    }
}

void PhysicsManager::stop()
{
    if (mEngine != NULL)
    {
        mEngine.stop();
    }
}

void PhysicsManager::update()
{
    if (mEngine != NULL)
    {
        mEngine.update();
    }
}