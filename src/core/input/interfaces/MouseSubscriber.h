#pragma once

#include <SFML/Window/Event.hpp>
#include "EventSubscriber.h"

namespace Game
{
class MouseSubscriber: public EventSubscriber
{
public:
    virtual void onMouseClick(sf::Event::MouseButtonEvent event) = 0;
    virtual void onMouseMove(sf::Event::MouseMoveEvent event) = 0;
    void onEvent(sf::Event event) override;
};
}
