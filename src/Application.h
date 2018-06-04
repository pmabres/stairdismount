#include "core/GameCore.h"

#ifndef GAME_APPLICATION_H
#define GAME_APPLICATION_H

namespace Game
{
    class Application
    {
    public:
        Application();
        virtual ~Application();
        void start();
    private:
        GameCore* mCore;
    };

}


#endif //GAME_APPLICATION_H
