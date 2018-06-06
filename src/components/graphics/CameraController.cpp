#include "CameraController.h"
#include "../../core/GameCore.h"

namespace Game
{
CameraController::CameraController()
{
}
CameraController::~CameraController()
{
    cleanup();
}

void CameraController::configure()
{
    mClean = false;
    mCamera = &entity->getComponent<Camera>();
    mRotator = new CameraRotator(*mCamera);
    mPositionShifter = new CameraPositionShifter(*mCamera);
    GameCore::get().getModule<EventModule>().subscribe(*mRotator);
    GameCore::get().getModule<EventModule>().subscribe(*mPositionShifter);
}

void CameraController::draw()
{
}

void CameraController::update()
{
}

void CameraController::start()
{

}
void CameraController::stop()
{

}
void CameraController::cleanup()
{
    if(!mClean)
    {
        mClean = true;
        delete mRotator;
        delete mPositionShifter;
    }
}
}
