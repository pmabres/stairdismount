#pragma once

#include <SFML/Window/Event.hpp>
#include "EventSubscriber.h"

namespace Game
{
class KeyboardSubscriber: public EventSubscriber
{
public:
    virtual void onKeyPress(sf::Event::KeyEvent event) = 0;
    virtual void onKeyDown(sf::Event::KeyEvent event) = 0;
    virtual void onKeyUp(sf::Event::KeyEvent event) = 0;
    void onEvent(sf::Event event) override;

};
}
