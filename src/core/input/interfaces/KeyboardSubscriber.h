#pragma once

#include <SFML/Window/Event.hpp>
#include "EventSubscriber.h"

class KeyboardSubscriber : public EventSubscriber {
public:
    virtual void onKeyPress(sf::Event::KeyEvent event) = 0;
    virtual void onKeyDown(sf::Event::KeyEvent event) = 0;
    virtual void onKeyUp(sf::Event::KeyEvent event) = 0;
private:
    void onEvent(sf::Event event) override;
};