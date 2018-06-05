#pragma once

#include <SFML/Window.hpp>
#include "graphics/DrawEngine.h"
#include <atomic>
#include "physics/PhysicsManager.h"
#include "time/GTime.h"
#include "input/EventManager.h"
#include "input/implementation/GameWindowListener.h"
#include "Configuration.h"

namespace Game
{
    class GameCore
    {
    public:

        virtual ~GameCore();
        void init();
        void stopGame();

        static GameCore& getInstance()
        {
            static GameCore instance; // Guaranteed to be destroyed.
            // Instantiated on first use.
            return instance;
        }
        GameCore(GameCore const&) = delete;
        void operator=(GameCore const&) = delete;

    private:
        GameCore();
        sf::Thread mRenderThread;
        sf::Window mWindow;
        DrawEngine mRenderer;
        std::atomic<bool> mRunning;
        PhysicsManager mPhysicsManager;
        EventManager mEventManager;
        GameWindowListener* mWindowListener;
        void gameLoop();
        void onRender();
        void onUpdate();
    };
}

