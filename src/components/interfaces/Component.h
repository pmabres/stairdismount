#pragma once

#include "../../core/entity/Entity.h"

namespace Game
{
class Entity;
class Component
{
public:
    void onComponentAdd(Entity* entity);
    void onComponentRemove();
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void configure() = 0;
    virtual void cleanup() = 0;
protected:
    Entity* entity;
};
inline void Component::onComponentAdd(Entity *entity)
{
    this->entity = entity;
}
inline void Component::onComponentRemove()
{
    this->entity = nullptr;
}
}
