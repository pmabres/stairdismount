#import "interfaces/IComponent.h"

#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H


class Component : public IComponent
{
public:
    virtual void onUpdate() = 0;
    virtual void onDraw() = 0;
};


#endif //GAME_COMPONENT_H
