#include "Camera.h"
#include "../../core/GameCore.h"


namespace Game
{
Camera::Camera()
{
    mRightVector = vec3(1.0, 0.0, 0.0);
    mUpVector = vec3(0.0, 1.0, 0.0);
    mCameraData.projectionMatrix = glm::perspective(mFov, 4.0f / 3.0f, 0.1f, 100.0f);
    mTransform.rotation.x = PI;
}
void Camera::configure()
{
}

void Camera::calculateVectors()
{
    // Right vector
    mRightVector = glm::vec3(
        sin(mTransform.rotation.x - PIHalf),
        0,
        cos(mTransform.rotation.x - PIHalf)
    );

    // Up vector
    mUpVector = glm::cross( mRightVector, mDirection );
}

void Camera::calculateViewMatrix()
{
    mCameraData.viewMatrix = glm::lookAt(
        mTransform.position,           // Camera is here
        mTransform.position + mDirection, // and looks here : at the same position, plus "direction"
        mUpVector                  // Head is up (set to 0,-1,0 to look upside-down)
    );
}

void Camera::rotateXY(float x, float y)
{
    mTransform.rotation.x += x;
    mTransform.rotation.y += y;
    mDirection = glm::vec3(cos(mTransform.rotation.y) * sin(mTransform.rotation.x),sin(mTransform.rotation.y),cos(mTransform.rotation.y) * cos(mTransform.rotation.x));
    calculateVectors();
    calculateViewMatrix();
}

void Camera::draw()
{
    GameCore::get().getModule<DrawModule>().setProjection(mCameraData);
}

void Camera::update()
{
    calculateVectors();
    checkMovement();
    checkKeyboardRotation();
    calculateVectors();
    calculateViewMatrix();
}

void Camera::start()
{

}
void Camera::stop()
{

}
void Camera::cleanup()
{

}
void Camera::checkMovement()
{
    //ignore time for now..GTime::getDelta()
    float totalSpeed = mSpeed; // * GTime::getDelta()

    if (mMoveUp)
    {
        mTransform.position += mDirection * totalSpeed;
    }
    if (mMoveLeft)
    {
        mTransform.position -= mRightVector  * totalSpeed;
    }
    if (mMoveRight)
    {
        mTransform.position +=  mRightVector  * totalSpeed;
    }
    if (mMoveDown)
    {
        mTransform.position -= mDirection * totalSpeed;
    }

}
void Camera::moveUp(bool pressed)
{
    mMoveUp = pressed;
}
void Camera::moveLeft(bool pressed)
{
    mMoveLeft = pressed;
}
void Camera::moveRight(bool pressed)
{
    mMoveRight = pressed;
}
void Camera::moveDown(bool pressed)
{
    mMoveDown = pressed;
}
void Camera::checkKeyboardRotation()
{
    //ignore time for now..GTime::getDelta()
    float totalSpeed = mRotationSpeed; // * GTime::getDelta()

    if (mRotateUp)
    {
        mTransform.rotation.y += totalSpeed;
    }
    if (mRotateRight)
    {
        mTransform.rotation.x -= totalSpeed;
    }
    if (mRotateLeft)
    {
        mTransform.rotation.x += totalSpeed;
    }
    if (mRotateDown)
    {
        mTransform.rotation.y -= totalSpeed;
    }

    mDirection = glm::vec3(cos(mTransform.rotation.y) * sin(mTransform.rotation.x),sin(mTransform.rotation.y),cos(mTransform.rotation.y) * cos(mTransform.rotation.x));
}
void Camera::rotateDown(bool pressed)
{
    mRotateDown = pressed;
}
void Camera::rotateRight(bool pressed)
{
    mRotateRight = pressed;
}
void Camera::rotateLeft(bool pressed)
{
    mRotateLeft = pressed;
}
void Camera::rotateUp(bool pressed)
{
    mRotateUp = pressed;
}
}
