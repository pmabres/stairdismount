#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../../core/input/interfaces/KeyboardSubscriber.h"
#include "../../core/input/interfaces/MouseSubscriber.h"
#include "../interfaces/Component.h"
#include "../../core/structs/CameraData.h"
#include "../../core/structs/Transform.h"

const float PI = glm::pi<float>();

const float PIHalf = glm::half_pi<float>();

using namespace glm;

namespace Game
{
class Camera: public Component
{
public:
    Camera(); //inits the values (Position: (0|0|0) Target: (0|0|-1) )
    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;
    void onCreate() override;
    //Note: You should call glLoadIdentity before using Render

    void rotateXY(float x, float y);
    void moveUp(bool pressed);
    void moveLeft(bool pressed);
    void moveRight(bool pressed);
    void moveDown(bool pressed);
    // KEYboard Rotations
    void rotateUp(bool pressed);
    void rotateLeft(bool pressed);
    void rotateRight(bool pressed);
    void rotateDown(bool pressed);
protected:

//        void onMouseClick(sf::Event::MouseButtonEvent event) override;
//        void onMouseMove(sf::Event::MouseMoveEvent event) override;
private:
    float mFov = 45.0f;
    float mSpeed = 0.01f; // 3 units / second;
    float mRotationSpeed = 0.001f;
    CameraData mCameraData;
    //TODO: Stop using this transform and start using the transform from the component of the entity.
    Transform mTransform;
    glm::vec3 mDirection;
    glm::vec3 mUpVector;
    glm::vec3 mRightVector;
    void calculateVectors();
    void calculateViewMatrix();
    void checkMovement();
    void checkKeyboardRotation();
    bool mMoveUp;
    bool mMoveDown;
    bool mMoveRight;
    bool mMoveLeft;

    bool mRotateUp;
    bool mRotateDown;
    bool mRotateRight;
    bool mRotateLeft;
};

}
