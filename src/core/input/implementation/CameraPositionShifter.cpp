#include <iostream>
#include "CameraPositionShifter.h"

namespace Game
{
CameraPositionShifter::CameraPositionShifter(Camera &camera)
    : mCamera(camera)
{
}

void CameraPositionShifter::onKeyPress(sf::Event::KeyEvent event)
{
    switch (event.code)
    {
    case sf::Keyboard::Down:
        mCamera.moveDown(true);
        break;
    case sf::Keyboard::Up:
        mCamera.moveUp(true);
        break;
    case sf::Keyboard::Left:
        mCamera.moveLeft(true);
        break;
    case sf::Keyboard::Right:
        mCamera.moveRight(true);
        break;
    case sf::Keyboard::J:
        mCamera.rotateLeft(true);
        break;
    case sf::Keyboard::L:
        mCamera.rotateRight(true);
        break;
    case sf::Keyboard::I:
        mCamera.rotateUp(true);
        break;
    case sf::Keyboard::K:
        mCamera.rotateDown(true);
        break;
    }
}

void CameraPositionShifter::onKeyUp(sf::Event::KeyEvent event)
{
    switch (event.code)
    {
    case sf::Keyboard::Down:
        mCamera.moveDown(false);
        break;
    case sf::Keyboard::Up:
        mCamera.moveUp(false);
        break;
    case sf::Keyboard::Left:
        mCamera.moveLeft(false);
        break;
    case sf::Keyboard::Right:
        mCamera.moveRight(false);
        break;
    case sf::Keyboard::J:
        mCamera.rotateLeft(false);
        break;
    case sf::Keyboard::L:
        mCamera.rotateRight(false);
        break;
    case sf::Keyboard::I:
        mCamera.rotateUp(false);
        break;
    case sf::Keyboard::K:
        mCamera.rotateDown(false);
        break;
    }
}

}

