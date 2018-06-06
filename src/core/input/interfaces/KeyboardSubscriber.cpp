#include "KeyboardSubscriber.h"

namespace Game
{
void KeyboardSubscriber::onEvent(sf::Event event)
{
    switch (event.type) {
    case sf::Event::KeyPressed:onKeyPress(event.key);
        break;
    case sf::Event::KeyReleased:onKeyUp(event.key);
        break;
    }
}
}
