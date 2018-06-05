#pragma once

#include "../interfaces/WindowSubscriber.h"
#include "../../GameCore.h"

class GameCore;

namespace Game
{
    class GameWindowListener : public WindowSubscriber
    {
    public:
        GameWindowListener(GameCore& core);
        void onWindowClose() override;
        void onWindowResize(int width, int height) override;
    private:
        GameCore& mCore;
    };

}
