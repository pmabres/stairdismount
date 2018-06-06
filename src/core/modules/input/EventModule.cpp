#include "EventModule.h"

namespace Game
{
EventModule::EventModule(sf::Window &window): mWindow(window)
{
}

void EventModule::update()
{
    sf::Event event{};
    while (mWindow.pollEvent(event)) {
        for (auto listener : mEventListeners) {
            listener.second.onEvent(event);
        }
    }
}

void EventModule::subscribe(EventSubscriber &event)
{
    mEventListeners.insert(std::pair<int, EventSubscriber &>(++mCurrentKey, event));
    event.subscribed(this, mCurrentKey);
}

void EventModule::unsubscribe(int hash)
{
    mEventListeners.erase(hash);
}
void EventModule::draw()
{

}
void EventModule::start()
{

}
void EventModule::stop()
{

}
void EventModule::configure()
{

}
void EventModule::cleanup()
{

}
}
