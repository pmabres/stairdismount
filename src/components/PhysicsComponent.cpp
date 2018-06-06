#include "PhysicsComponent.h"
#include "TransformComponent.h"
namespace Game
{
PhysicsComponent::PhysicsComponent()
{
}

PhysicsComponent::~PhysicsComponent()
{

}
void PhysicsComponent::update()
{
    if (mConfigured)
    {
        Transform transform = mPhysicsObject->transform().fromPhysics();
        entity->getComponent<TransformComponent>().setTransform(transform);
    }

}
void PhysicsComponent::draw()
{

}
void PhysicsComponent::start()
{
}
void PhysicsComponent::stop()
{

}
void PhysicsComponent::configure()
{
//    mConfigured = true;
//    mPhysicsObject = GameCore::get().getModule<PhysicsModule>()
//        .createPhysicsObject(entity->getComponent<TransformComponent>().getTransform());
}
void PhysicsComponent::cleanup()
{
    mConfigured = false;
}


}
