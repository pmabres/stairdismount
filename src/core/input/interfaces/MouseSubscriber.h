#pragma once

#include <SFML/Window/Event.hpp>
#include "EventSubscriber.h"

class MouseSubscriber : public EventSubscriber {
public:
    virtual void onMouseClick(sf::Event::MouseButtonEvent event) = 0;
    virtual void onMouseMove(sf::Event::MouseMoveEvent event) = 0;
private:
    void onEvent(sf::Event event) override;
};