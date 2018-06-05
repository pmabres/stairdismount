#include "MouseSubscriber.h"

void MouseSubscriber::onEvent(sf::Event event)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:
            onMouseClick(event.mouseButton);
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove);
            break;
    }
}
