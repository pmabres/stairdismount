#pragma once

#include <list>
#include <unordered_map>
#include <SFML/Window.hpp>
#include "interfaces/EventSubscriber.h"

class EventSubscriber;

class EventManager {
public:
    EventManager();
    void subscribe(EventSubscriber& event);
    void unsubscribe(int hash);
    void update(sf::Window &window);

private:
    std::unordered_map<int, EventSubscriber&> mEventListeners;
    int mCurrentKey = -1;
};


