#pragma once
#include <SFML/Window.hpp>
#include <atomic>
#include "modules/graphics/DrawModule.h"
#include "modules/physics/PhysicsModule.h"
#include "modules/input/EventModule.h"
#include "modules/entities/EntitiesModule.h"
#include "modules/ModuleManager.h"
#include "time/GTime.h"
#include "input/implementation/GameWindowListener.h"

namespace Game
{

class GameWindowListener;
class GameCore
{
public:
    void init();
    void stopGame();
    sf::Window& getWindow();
    Entity* addEntity();

    template<class T>
    T& getModule()
    {
        return mModuleManager.get<T>();
    }

    static GameCore& get()
    {
        static GameCore instance;
        return instance;
    }
    GameCore(GameCore const &) = delete;
    void operator=(GameCore const &) = delete;

private:
    GameCore();
    ~GameCore();
    sf::Thread mRenderThread;
    sf::Window mWindow;
    std::atomic<bool> mRunning;
    GameWindowListener *mWindowListener;
    ModuleManager mModuleManager;
    void gameLoop();
    void onRender();
    void onUpdate();
};

}

