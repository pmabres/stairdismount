#include <iostream>
#include "GameCore.h"

namespace Game
{
GameCore::GameCore()
    :
    mWindow(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(24, 8, 0, 2, 1 )),
    mRenderThread(&GameCore::gameLoop, this),
    mWindowListener(new GameWindowListener(*this))
{
}

GameCore::~GameCore()
{
    delete mWindowListener;
}

void GameCore::init()
{
    mWindow.setActive(false);
    mModuleManager.add(new DrawModule());
    mModuleManager.add(new EventModule(mWindow));
    mModuleManager.add(new PhysicsModule());
    getModule<EventModule>().subscribe(*mWindowListener);
    auto physicsModule = getModule<PhysicsModule>();
    physicsModule.createEngine(PhysicsEngines::Bullet);
    mModuleManager.configure();
    mRunning = true;
    gameLoop();
//        mRenderThread.launch();
//        mRenderThread.wait();
}

void GameCore::gameLoop()
{
    mWindow.setActive(true);
    mModuleManager.start();
    while (mRunning) {
        onUpdate();
        onRender();
    }
    mModuleManager.stop();
}
void GameCore::onRender()
{
    mModuleManager.draw();
    mWindow.display();
}

void GameCore::onUpdate()
{
    GTime::update(mWindow);
    mModuleManager.update();

}

void GameCore::stopGame()
{
    mRunning = false;
}

template<class T>
T &GameCore::getModule()
{
    return mModuleManager.get<T>();
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