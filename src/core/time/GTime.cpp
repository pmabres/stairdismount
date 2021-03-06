#include <iostream>
#include "GTime.h"
namespace Game
{
sf::Time GTime::mElapsed;

sf::Time GTime::mTotal;

sf::Clock GTime::mClock;

void GTime::update(const sf::Window &window)
{
    if (window.isOpen()) {
        GTime::mElapsed = GTime::mClock.restart();
        GTime::mTotal += GTime::mElapsed;
    }

}

uint32_t GTime::getDelta()
{
    return GTime::mElapsed.asMilliseconds();
}

uint64_t GTime::getDeltaMicro()
{
    return GTime::mElapsed.asMicroseconds();
}

uint32_t GTime::getTotal()
{
    return GTime::mTotal.asMilliseconds();
}
}
