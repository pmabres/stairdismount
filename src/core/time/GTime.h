#pragma once

#include <SFML/Window.hpp>

namespace Game
{
class GTime final
{
public:
    static uint32_t getDelta();
    static uint32_t getTotal();
    static uint64_t getDeltaMicro();
    static void update(const sf::Window &window);

private:
    static sf::Clock mClock;
    static sf::Time mElapsed;
    static sf::Time mTotal;
    GTime() = default;
};
}

