#include <atomic>

#ifndef GAME_PHYSICSENGINE_H
#define GAME_PHYSICSENGINE_H
class PhysicsEngine {
    virtual void configure() = 0;
    virtual void start() = 0;
    virtual void update() = 0;
    virtual void stop() = 0;
    virtual void destroy() = 0;
    virtual Atomic<bool> mRunning;
    virtual Atomic<bool> mInitialized;
};
#endif //GAME_PHYSICSENGINE_H
