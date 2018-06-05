#pragma once

class IComponent
{
public:
    virtual void onUpdate() = 0;
    virtual void onDraw() = 0;
};
