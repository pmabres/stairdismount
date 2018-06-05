#pragma once

namespace Game
{
    class Configuration
    {
    public:
        static void SetSize(uint32 width, uint32 height)
        {
            Configuration::width = width;
            Configuration::height = height;
        }
        static uint32 GetWidth() { return Configuration::width; }
        static uint32 GetHeight() { return Configuration::height; }
    private:
        static uint32 width;
        static uint32 height;
    };
}
