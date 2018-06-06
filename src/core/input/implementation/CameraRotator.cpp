#include "GameWindowListener.h"

namespace Game
{
GameWindowListener::GameWindowListener(Camera &camera)
    : mCamera(camera)
{
}

void GameWindowListener::onWindowClose()
{
    mCore.stopGame();
}

void GameWindowListener::onWindowResize(int width, int height)
{

}
}
