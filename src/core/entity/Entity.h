#pragma once

#include <unordered_map>
#include <typeindex>
#include "../../components/interfaces/Component.h"
#include "../../core/modules/interfaces/Module.h"

namespace Game
{
class Component;
class Entity : public Module
{
public:
    Entity();
    ~Entity();
    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;
    void setId(uint32_t uid);
    void addComponent(Component* component);
    void removeAndStopComponent(Component* component);
    template<class T>
    T& getComponent()
    {
        return static_cast<T&> (*mComponents.find(typeid(T))->second);
    }
    template<class T>
    void removeComponent()
    {
        auto it = mComponents.find(typeid(T));
        removeAndStopComponent(it->second);
        mComponents.erase(it);
    }
private:
    uint32_t mUid;
    std::unordered_map<std::type_index, Component* > mComponents;
};
}
