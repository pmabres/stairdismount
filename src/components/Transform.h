#include "../core/system/Component.h"

#ifndef GAME_TRANSFORM_H
#define GAME_TRANSFORM_H


class Transform : Component
{
    Transform();
    ~Transform();


private:
    virtual void onDraw();
    virtual void onUpdate();
};


#endif //GAME_TRANSFORM_H

