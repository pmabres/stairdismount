#pragma once

#import "interfaces/IComponent.h"

class Component : public IComponent
{
public:
    virtual void onUpdate() = 0;
    virtual void onDraw() = 0;
};
