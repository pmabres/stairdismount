#include "GameWindowListener.h"
namespace Game
{
    GameWindowListener::GameWindowListener(GameCore& core) : mCore(core)
    {
    }

    void GameWindowListener::onWindowClose()
    {
        mCore->stopGame();
    }

    void GameWindowListener::onWindowResize(int width, int height)
    {

    }
}
