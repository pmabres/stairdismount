#include "Application.h"

namespace Game
{
Application::Application()
{
}

Application::~Application()
{
}

void Application::start()
{
    GameCore::get().init();
}
}