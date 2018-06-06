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

}
void PhysicsComponent::cleanup()
{

}


}
