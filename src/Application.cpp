#include "Application.h"

namespace Game
{
    Application::Application() : mCore(GameCore::getInstance())
    {
        Configuration::SetSize(800, 600);
    }

    Application::~Application()
    {
    }

    void Application::start()
    {
        mCore.init();
    }
}