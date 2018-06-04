#include "Application.h"
namespace Game
{
    Application::Application()
    {
        mCore = new GameCore(800, 600);
    }

    Application::~Application()
    {
        delete mCore;
    }

    void Application::start()
    {
        mCore->init();
    }
}