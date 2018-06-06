#pragma once

namespace Game
{
class PhysicsEngine
{
public:
    virtual void configure() = 0;
    virtual void start() = 0;
    virtual void update() = 0;
    virtual void stop() = 0;
    virtual void destroy() = 0;
};
}

