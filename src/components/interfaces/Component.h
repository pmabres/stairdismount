#pragma once

namespace Game
{
class Component
{
public:
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void start() = 0;
};
}
