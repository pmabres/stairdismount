#pragma once

#include "interfaces/Component.h"
#include "../core/GameCore.h"
namespace Game
{
class PhysicsComponent: Component
{
public:
    PhysicsComponent();
    ~PhysicsComponent();

    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;
private:


};

}
