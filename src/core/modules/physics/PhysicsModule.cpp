#include "PhysicsModule.h"

namespace Game
{
PhysicsModule::PhysicsModule()
{
}

void PhysicsModule::createEngine(PhysicsEngines engine)
{
    mPhysicsManager.createEngine(engine);
}

void PhysicsModule::deleteEngine()
{
    mPhysicsManager.deleteEngine();
}

void PhysicsModule::update()
{
    mPhysicsManager.update();
}

void PhysicsModule::draw()
{
}
void PhysicsModule::start()
{
    mPhysicsManager.start();
}
void PhysicsModule::stop()
{
    mPhysicsManager.stop();
}
void PhysicsModule::configure()
{
    mPhysicsManager.configure();
}
void PhysicsModule::cleanup()
{
    mPhysicsManager.deleteEngine();
}

PhysicsObject *PhysicsModule::createPhysicsObject(Transform transform)
{
    return mPhysicsManager.createObject(transform);
}
}
