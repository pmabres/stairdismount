#include "GameWindowListener.h"

namespace Game
{
GameWindowListener::GameWindowListener()
{
}

void GameWindowListener::onWindowClose()
{
    GameCore::get().stopGame();
}

void GameWindowListener::onWindowResize(int width, int height)
{
    //GameCore::get().resizeWindow(width, height);
}
}
