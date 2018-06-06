#pragma once

#include "../interfaces/KeyboardSubscriber.h"
#include "../../../components/graphics/Camera.h"

namespace Game
{
class CameraPositionShifter: public KeyboardSubscriber
{
public:
    CameraPositionShifter(Camera& camera);
    void onKeyPress(sf::Event::KeyEvent event) override;
    void onKeyUp(sf::Event::KeyEvent event) override;
private:
    Camera& mCamera;
};

}
