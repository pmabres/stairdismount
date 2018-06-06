#pragma once

#include "interfaces/Module.h"
#include <unordered_map>
#include <typeindex>
namespace Game
{
class ModuleManager final : Module
{
public:
    ModuleManager() = default;
    ~ModuleManager() = default;
    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;
    void add(Module* entity);
    template<class T>
    T& get();
private:
    std::unordered_map<std::type_index, Module* > mModules;
};

}

