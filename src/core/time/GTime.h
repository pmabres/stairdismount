#pragma once

#include <SFML/Window.hpp>

class GTime final
{
public:
    static uint32_t getDelta();
    static uint32_t getTotal();
    static void update(const sf::Window& window);

private:
    static sf::Time mElapsed;
    static sf::Time mTotal;
    GTime() = default;
};
