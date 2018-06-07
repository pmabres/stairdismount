#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "MeshComponent.h"
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

}
void PhysicsComponent::cleanup()
{
    mConfigured = false;
}
void PhysicsComponent::setShape(CollisionShapes shape)
{
    mPhysicsObject->setShape(shape);
}
void PhysicsComponent::setMass(float mass)
{
    mPhysicsObject->setMass(mass);
}
void PhysicsComponent::onCreate()
{
    mConfigured = true;
    mPhysicsObject = GameCore::get().getModule<PhysicsModule>()
        ->createPhysicsObject(entity->getComponent<TransformComponent>().getTransform());
    mPhysicsObject->setMesh(&entity->getComponent<MeshComponent>().getMeshData());
}

}
