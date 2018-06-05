#pragma once

#include "interfaces/PhysicsEngine.h"
#include "bullet/Loader.h"

enum class Engines { Bullet };
class PhysicsManager final
{
public:
    PhysicsManager();
    ~PhysicsManager();

    void createEngine(Engines engine);
    void deleteEngine();
    void configure();
    void start();
    void stop();
    void update();
private:
    PhysicsEngine* mEngine;
};
