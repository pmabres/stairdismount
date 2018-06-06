#pragma once

#include "../../GameCore.h"
#include "../../../components/graphics/Camera.h"
namespace Game
{
class GameCore;
class CameraRotator: public MouseSubscriber
{
public:
    CameraRotator(Camera& camera);
    virtual void onMouseClick(sf::Event::MouseButtonEvent event) override;
    virtual void onMouseMove(sf::Event::MouseMoveEvent event) override;
private:
    Camera &mCamera;
};

}
