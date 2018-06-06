#pragma once

#include "../../entity/Entity.h"
#include "../interfaces/Module.h"
#include <unordered_map>
#include <typeindex>
namespace Game
{
class EntitiesModule : public Module
{
public:
    EntitiesModule();
    ~EntitiesModule();
    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;
    Entity* add();
    Entity* get(uint32_t id);
private:
    uint32_t mInternalId;
    std::unordered_map<uint32_t, Entity* > mEntities;
};

}

