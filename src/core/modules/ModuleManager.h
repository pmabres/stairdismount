#pragma once

#include "interfaces/Module.h"
#include <unordered_map>
#include <typeindex>
#include <map>
namespace Game
{
class ModuleManager : public Module
{
public:
    ModuleManager();
    ~ModuleManager();
    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;
    void add(Module* module);
    template<class T>
    T& get()
    {
        return static_cast<T&> (*mModules.find(typeid(T))->second);
    }
private:
    std::map<std::type_index, Module* > mModules;
};

}

