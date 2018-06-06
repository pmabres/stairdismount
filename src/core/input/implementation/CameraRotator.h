#pragma once

#include "../../../components/graphics/Camera.h"
namespace Game
{
class CameraRotator: public MouseSubscriber
{
public:
    CameraRotator(Camera& camera);
    void onMouseClick(sf::Event::MouseButtonEvent event) override;
    void onMouseMove(sf::Event::MouseMoveEvent event) override;
private:
    Camera &mCamera;
    float mMouseSpeed = 0.5f;
};

}
