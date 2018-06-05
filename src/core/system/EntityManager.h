#pragma once

#include "interfaces/IEntity.h"

class EntityManager
{
public:
    EntityManager();
    virtual ~EntityManager();
    void addEntity(IEntity entity);
};
