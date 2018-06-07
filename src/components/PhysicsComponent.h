#pragma once

#include "interfaces/Component.h"
#include "../core/GameCore.h"
#include "../core/physics/CollisionShapes.h"
namespace Game
{
class PhysicsComponent: public Component
{
public:
    PhysicsComponent();
    ~PhysicsComponent();

    void setMass(float mass);
    void setShape(CollisionShapes shape);
    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;
    void onCreate() override;
private:
    PhysicsObject* mPhysicsObject;
    bool mConfigured;
};

}
