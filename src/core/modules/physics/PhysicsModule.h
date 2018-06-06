#pragma once

#include "../../physics/PhysicsManager.h"

namespace Game
{
class PhysicsModule : Module
{
public:
    PhysicsModule();
    void createEngine(PhysicsEngines engine);
    void deleteEngine();
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