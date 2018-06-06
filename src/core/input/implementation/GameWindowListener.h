#pragma once

#include "../interfaces/WindowSubscriber.h"
#include "../../GameCore.h"

namespace Game
{
class GameCore;
class GameWindowListener: public WindowSubscriber
{
public:
    GameWindowListener();
    void onWindowClose() override;
    void onWindowResize(int width, int height) override;
};

}
