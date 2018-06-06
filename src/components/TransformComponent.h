#pragma once

#include "../core/system/Component.h"

class TransformComponent: Component
{
    TransformComponent();
    ~TransformComponent();


private:
    virtual void onDraw();
    virtual void onUpdate();
};

