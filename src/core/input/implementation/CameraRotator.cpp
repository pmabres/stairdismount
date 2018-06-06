#include "CameraRotator.h"
#include "../../GameCore.h"
namespace Game
{
CameraRotator::CameraRotator(Camera &camera)
    : mCamera(camera)
{
}
void CameraRotator::onMouseClick(sf::Event::MouseButtonEvent event)
{

}
void CameraRotator::onMouseMove(sf::Event::MouseMoveEvent event)
{
    sf::Vector2u size = GameCore::get().getWindow().getSize();
    std::cout << float(size.x/2 - event.x ) << std::endl;
    //mCamera.rotateXY(mMouseSpeed * float(size.x/2 - event.x ), mMouseSpeed * float( size.y/2 - event.y ));
   // sf::Mouse::setPosition(sf::Vector2i(size.x/2, size.y/2), GameCore::get().getWindow());

}
}
