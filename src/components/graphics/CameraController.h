#pragma once
#include "../interfaces/Component.h"
#include "../../core/input/implementation/CameraRotator.h"
#include "../../core/input/implementation/CameraPositionShifter.h"
namespace Game
{
class CameraController: public Component
{
public:
    CameraController();
    ~CameraController();
    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;
    void onCreate() override;
    //Note: You should call glLoadIdentity before using Render
private:
    CameraPositionShifter* mPositionShifter;
    CameraRotator* mRotator;
    Camera* mCamera;
    bool mClean;
};

}
