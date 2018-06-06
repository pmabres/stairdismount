#pragma once

#include "../../modules/input/EventModule.h"
#include <SFML/Window/Event.hpp>

namespace Game
{
class EventModule;

class EventSubscriber
{
public:
    virtual ~EventSubscriber();
    virtual void subscribed(EventModule *manager, int hash) final;
    virtual void onEvent(sf::Event event) = 0;
private:
    EventModule *mManager = nullptr;
    int mHash = 0;
};

}
