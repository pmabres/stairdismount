#ifndef GAME_ICOMPONENT_H
#define GAME_ICOMPONENT_H

class IComponent
{
public:
    virtual void onUpdate() = 0;
    virtual void onDraw() = 0;
};

#endif //GAME_ICOMPONENT_H
