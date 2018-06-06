#pragma once

#include "../interfaces/WindowSubscriber.h"
#include "../../GameCore.h"

namespace Game
{
class GameCore;
class GameWindowListener: public KeyboardSubscriber
{
public:
    GameWindowListener(GameCore &core);
    void onWindowClose() override;
    void onWindowResize(int width, int height) override;
private:
    GameCore &mCore;
};

}
