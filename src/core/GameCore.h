#include <SFML/Window.hpp>
#include "graphics/DrawEngine.h"
#include <atomic>
#include "physics/PhysicsManager.h"

#ifndef GLGAME_GAMECORE_H
#define GLGAME_GAMECORE_H


namespace Game
{
    class GameCore
    {
    public:

        GameCore(const sf::Uint32 &width, const sf::Uint32 &height);
        virtual ~GameCore( );

        void init();


    private:
        sf::Thread mRenderThread;
        sf::Window mWindow;
        DrawEngine mRenderer;
        std::atomic<bool> mRunning;
        PhysicsManager mPhysicsManager;
        void gameLoop();
        void onRender();
        void onUpdate();
    };

}

#endif //GLGAME_GAMECORE_H

