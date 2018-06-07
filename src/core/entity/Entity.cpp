#include "Entity.h"
#include "../../components/TransformComponent.h"

namespace Game 
{
Entity::Entity() : mComponents()
{
    addComponent(new TransformComponent());
}

Entity::~Entity()
{
    cleanup();
}

void Entity::addComponent(Component *component)
{
    component->onComponentAdd(this);
    mComponents.insert(std::pair<std::type_index, Component *>(typeid(*component), component));
}


void Entity::start()
{
    for (auto element : mComponents) {
        element.second->start();
    }
}

void Entity::stop()
{
    for (auto element : mComponents) {
        element.second->stop();
    }
}

void Entity::update()
{
    for (auto element : mComponents) {
        element.second->update();
    }
}

void Entity::draw()
{
    for (auto element : mComponents) {
        element.second->draw();
    }
}

void Entity::configure()
{
    for (auto element : mComponents) {
        element.second->configure();
    }
}

void Entity::removeAndStopComponent(Component* component)
{
    component->stop();
    component->cleanup();
    component->onComponentRemove();
    delete component;
}

void Entity:: cleanup()
{
    while (!mComponents.empty()) {
        auto it = mComponents.begin();
        if (it->second != NULL) {
            removeAndStopComponent(it->second);
        }
        mComponents.erase(it);
    }
}
void Entity::setId(uint32_t uid)
{
    mUid = uid;
}

}
