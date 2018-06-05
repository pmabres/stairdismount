#include "EventManager.h"

EventManager::EventManager()
{

}

void EventManager::update(sf::Window &window)
{
    sf::Event event {};
    while (window.pollEvent(event))
    {
        for ( auto listener : mEventListeners )
        {
            listener.second.onEvent(event);
        }
    }
}

void EventManager::subscribe(EventSubscriber& event)
{
    mEventListeners.insert(std::pair<int, EventSubscriber&>(++mCurrentKey, event));
    event.subscribed(this, mCurrentKey);
}


void EventManager::unsubscribe(int hash)
{
    mEventListeners.erase(hash);
}