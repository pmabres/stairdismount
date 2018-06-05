#pragma once

#include "../EventManager.h"
#include <SFML/Window/Event.hpp>

class EventManager;

class EventSubscriber {
public:
    virtual ~EventSubscriber();
    virtual void subscribed(EventManager* manager,  int hash) final;
    virtual void onEvent(sf::Event event) = 0;
private:
    EventManager* mManager = nullptr;
    int mHash = 0;
};
