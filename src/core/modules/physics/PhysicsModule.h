#pragma once

#include "../../physics/PhysicsManager.h"
#include "../interfaces/Module.h"

namespace Game
{
class PhysicsModule : public Module
{
public:
    PhysicsModule();
    void createEngine(PhysicsEngines engine);
    void deleteEngine();
    PhysicsObject* createPhysicsObject(Transform transform);
    void update() override;
    virtual void draw() override;
    virtual void start() override;
    virtual void stop() override;
    virtual void configure() override;
    virtual void cleanup() override;
private:
    PhysicsManager mPhysicsManager;

};
}