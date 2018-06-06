#pragma once

#include <SFML/Window/Event.hpp>
#include "EventSubscriber.h"

namespace Game
{
class WindowSubscriber: public EventSubscriber
{
public:
    virtual void onWindowClose() = 0;
    virtual void onWindowResize(int width, int height) = 0;
    void onEvent(sf::Event event) override;
};

}
