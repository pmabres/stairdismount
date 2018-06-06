#include "WindowSubscriber.h"

namespace Game
{
void WindowSubscriber::onEvent(sf::Event event)
{
    switch (event.type) {
    case sf::Event::Closed:onWindowClose();
        break;
    case sf::Event::Resized:onWindowResize(event.size.width, event.size.height);
        break;
    }
}

}
