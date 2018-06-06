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
   Transform transform = entity->getComponent<TransformComponent>().getTransform();
    setTransform
}
void PhysicsComponent::draw()
{

}
void PhysicsComponent::start()
{
   //GameCore::get().getModule<PhysicsModule>().addRigidBody(mRigidBody);
}
void PhysicsComponent::stop()
{

}
void PhysicsComponent::configure()
{

}
void PhysicsComponent::cleanup()
{

}


}
