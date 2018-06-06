#pragma once

#include <GL/glew.h>
//#include "Camera.h"
#include "../interfaces/Module.h"

namespace Game
{

class DrawModule : Module
{
public:
    DrawModule() = default;
    ~DrawModule() = default;
    void draw() override;
    void update() override;
    void configure() override;
    void start() override;
    void stop() override;
    void cleanup() override;
    //void resize(const sf::Uint32 &width, const sf::Uint32 &height);
private:
//    Camera mCamera;
};
}
