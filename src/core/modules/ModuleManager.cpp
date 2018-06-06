#include "ModuleManager.h"

namespace Game
{

ModuleManager::ModuleManager() : mModules()
{
}

template<class T>
T &ModuleManager::get()
{
    return static_cast<T &> (mModules.find(typeid(T)));
}
void ModuleManager::add(Module *entity)
{
    mModules.insert(std::pair<std::type_index, Module *>(typeid(*entity), entity));
}
ModuleManager::~ModuleManager()
{
    cleanup();
}

void ModuleManager::start()
{
    for (auto element : mModules) {
        element.second->start();
    }
}

void ModuleManager::stop()
{
    for (auto element : mModules) {
        element.second->stop();
    }
}

void ModuleManager::update()
{
    for (auto element : mModules) {
        element.second->update();
    }
}

void ModuleManager::draw()
{
    for (auto element : mModules) {
        element.second->draw();
    }
}

void ModuleManager::configure()
{
    for (auto element : mModules) {
        element.second->configure();
    }
}

void ModuleManager::cleanup()
{
    while (!mModules.empty()) {
        auto it = mModules.begin();
        if (it->second != NULL) {
            it->second->cleanup();
            delete it->second;
        }
        mModules.erase(it);
    }
}

}