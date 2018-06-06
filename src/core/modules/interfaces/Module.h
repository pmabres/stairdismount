#pragma once

namespace Game
{
class Module
{
public:
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void configure() = 0;
    virtual void cleanup() = 0;
};
}
