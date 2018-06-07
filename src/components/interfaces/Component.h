#pragma once

#include "../../core/entity/Entity.h"

namespace Game
{
class Entity;
class Component
{
public:
    void onComponentAdd(Entity *entity)
    {
        this->entity = entity;
        onCreate();
    };
    void onComponentRemove()
    {
        this->entity = nullptr;
    }
    virtual void onCreate() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void configure() = 0;
    virtual void cleanup() = 0;
protected:
    Entity* entity;
};
}
