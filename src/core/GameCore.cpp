#include <iostream>
#include "GameCore.h"

namespace Game
{
    GameCore::GameCore(const sf::Uint32& width, const sf::Uint32& height) :
            mWindow(sf::VideoMode(width, height), "OpenGL"),
            mRenderThread(&GameCore::gameLoop, this)
    {
    }

    GameCore::~GameCore()
    {
    }

    void GameCore::init()
    {
        mWindow.setActive(false);
        mPhysicsManager.createEngine(Engines::Bullet);
        mPhysicsManager.configure();
        mRunning = true;
        gameLoop();
//        mRenderThread.launch();
//        mRenderThread.wait();
    }

    void GameCore::gameLoop()
    {
        mWindow.setActive(true);
        mPhysicsManager.start();
        while (mRunning)
        {
            onRender();
            onUpdate();
        }
        mPhysicsManager.stop();
    }
    void GameCore::onRender()
    {
        sf::Event event {};
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Resized)
            {
                mRenderer.resize(event.size.width, event.size.height);
            }
        }
        mRenderer.draw();
        mWindow.display();
    }

    void GameCore::onUpdate()
    {
        mPhysicsManager.update();
        // handle events
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Closing window" << std::endl;
                mRunning = false;
            }
        }
    }
}
//
//
//
//const int TICKS_PER_SECOND = 25;
//const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
//const int MAX_FRAMESKIP = 5;
//
////StateManager TargetState;
//
//int main()
//{
//    // Game loop variables
//    sf::Clock ticker;
//    sf::Int32 next_game_tick = ticker.getElapsedTime().asMilliseconds();
//    int loops;
//    float interpolation;
//
//    //TargetState.changeState(MenuState::Instance(&Window));
//
//    sf::Font font;
//    font.loadFromFile("arial.ttf");
//
//    while(Window.isOpen()) {
//        //TargetState.input();
//
//        // Update the game
//        loops = 0;
//        while(ticker.getElapsedTime().asMilliseconds() > next_game_tick && loops < MAX_FRAMESKIP) {
//            //TargetState.update();
//            next_game_tick += SKIP_TICKS;
//            ++loops;
//
//            sf::Event event;
//            while(Window.pollEvent(event))
//            {
//                if(event.type == sf::Event::Closed)
//                    Window.close();
//            }
//        }
//
//        interpolation = float(ticker.getElapsedTime().asMilliseconds() + SKIP_TICKS - next_game_tick)
//                        / float (SKIP_TICKS);
//
//
//
//        Window.display();
//    }
//    return 0;
//}