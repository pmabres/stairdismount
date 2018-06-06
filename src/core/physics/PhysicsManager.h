#pragma once

#include "interfaces/PhysicsEngine.h"
#include "bullet/Loader.h"

namespace Game
{
enum class PhysicsEngines
{
    Bullet
};
class PhysicsManager final
{
public:
    PhysicsManager();
    ~PhysicsManager();

    void createEngine(PhysicsEngines engine);
    void deleteEngine();
    void configure();
    void start();
    void stop();
    void update();
private:
    PhysicsEngine *mEngine;
};

}
