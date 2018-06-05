//
// Created by pancho on 6/5/18.
//

#include "GTime.h"

void GTime::update(const sf::Window &window)
{
    sf::Clock clock;
    if (window.isOpen())
    {
        mElapsed = clock.restart();
        mTotal += mElapsed;
    }

}

uint32_t GTime::getDelta() {
    return mElapsed.asMilliseconds();
}

uint32_t GTime::getTotal() {
    return mTotal.asMilliseconds();
}
