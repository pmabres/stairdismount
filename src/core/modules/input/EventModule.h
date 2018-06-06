#pragma once

#include <list>
#include <unordered_map>
#include <SFML/Window.hpp>
#include "../../input/interfaces/EventSubscriber.h"
#include "../interfaces/Module.h"

namespace Game
{
class EventSubscriber;

class EventModule : Module
{
public:
    EventModule(sf::Window &window);
    void subscribe(EventSubscriber &event);
    void unsubscribe(int hash);
    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;

private:
    std::unordered_map<int, EventSubscriber &> mEventListeners {};
    int mCurrentKey = -1;
    sf::Window &mWindow;
};

}
