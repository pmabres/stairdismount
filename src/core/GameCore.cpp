#include <iostream>
#include "GameCore.h"
#include "input/EventManager.h"

namespace Game
{
    GameCore::GameCore() :
            mWindow(sf::VideoMode(Configuration::GetWidth(), Configuration::GetHeight()), "OpenGL"),
            mRenderThread(&GameCore::gameLoop, this)
    {
        mWindowListener = new GameWindowListener(*this);
    }

    GameCore::~GameCore()
    {
        delete mWindowListener;
    }

    void GameCore::init()
    {
        mWindow.setSize(sf::Vector2(Configuration::GetWidth(), Configuration::GetHeight()));
        mWindow.setActive(false);
        mEventManager.subscribe(*mWindowListener);
        mPhysicsManager.createEngine(Engines::Bullet);
        mPhysicsManager.configure();
        mRunning = true;
        gameLoop();
//        mRenderThread.launch();
//        mRenderThread.wait();
    }

    void GameCore::gameLoop()
    {
        mRenderer.configure();
        mWindow.setActive(true);
        mPhysicsManager.start();
        while (mRunning)
        {
            onUpdate();
            onRender();
        }
        mPhysicsManager.stop();
    }
    void GameCore::onRender()
    {

        mRenderer.draw();
        mWindow.display();
    }

    void GameCore::onUpdate()
    {
        GTime::update(mWindow);
        mEventManager.update(mWindow);
        mPhysicsManager.update();

    }

    void GameCore::stopGame()
    {
        mRunning = false;
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