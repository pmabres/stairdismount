#include "EntitiesModule.h"

namespace Game
{

EntitiesModule::EntitiesModule() : mEntities()
{
}

EntitiesModule::~EntitiesModule()
{
    cleanup();
}

Entity* EntitiesModule::get(uint32_t id)
{
    return mEntities.find(id)->second;
}

Entity* EntitiesModule::add()
{
    auto entity = new Entity();
    mEntities.insert(std::pair<uint32_t, Entity*>(++mInternalId, entity));
    entity->setId(mInternalId);
    return entity;
}

void EntitiesModule::start()
{
    for (auto element : mEntities) {
        element.second->start();
    }
}

void EntitiesModule::stop()
{
    for (auto element : mEntities) {
        element.second->stop();
    }
}

void EntitiesModule::update()
{
    for (auto element : mEntities) {
        element.second->update();
    }
}

void EntitiesModule::draw()
{
    for (auto element : mEntities) {
        element.second->draw();
    }
}

void EntitiesModule::configure()
{
    for (auto element : mEntities) {
        element.second->configure();
    }
}

void EntitiesModule::cleanup()
{
    while (!mEntities.empty()) {
        auto it = mEntities.begin();
        if (it->second != NULL) {
            it->second->cleanup();
            delete it->second;
        }
        mEntities.erase(it);
    }
}

}