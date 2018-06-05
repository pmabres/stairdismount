#pragma once

#include "core/GameCore.h"
#include "core/Configuration.h"

namespace Game
{
    class Application
    {
    public:
        Application();
        virtual ~Application();
        void start();
    private:
        GameCore& mCore;
    };

}