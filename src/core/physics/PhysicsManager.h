#include "interfaces/PhysicsEngine.h"
#include "bullet/Loader.h"
#ifndef GAME_PHYSICSMANAGER_H
#define GAME_PHYSICSMANAGER_H

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
    PhysicsEngine mEngine;
};


#endif //GAME_PHYSICSMANAGER_H
