#pragma once

#include <GL/glew.h>
#include <SFML/System.hpp>
#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>
#include <glm/glm.hpp>
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../../core/input/interfaces/KeyboardSubscriber.h"
#include "../../core/input/interfaces/MouseSubscriber.h"
#include "../interfaces/Component.h"

const float PI = glm::pi<float>();

const float PIHalf = glm::half_pi<float>();

using namespace glm;

namespace Game
{
class Camera : public KeyboardSubscriber, public Component
{
public:
    Camera(); //inits the values (Position: (0|0|0) Target: (0|0|-1) )
    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;
    //Note: You should call glLoadIdentity before using Render

    void move(const vec3 &direction);
    void rotateX(float angle);
    void rotateY(float angle);
    void rotateZ(float angle);

    void moveForward(float distance);
    void moveUpward(float distance);
    void strafeRight(float distance);
    mat4x4 lookAt(vec3 position, vec3 viewPoint, vec3 upVector);
protected:
    void onKeyPress(sf::Event::KeyEvent event) override;
    void onKeyDown(sf::Event::KeyEvent event) override;
    void onKeyUp(sf::Event::KeyEvent event) override;
//        void onMouseClick(sf::Event::MouseButtonEvent event) override;
//        void onMouseMove(sf::Event::MouseMoveEvent event) override;
private:

    vec3 mViewDir;
    vec3 mRightVector;
    vec3 mUpVector;
    vec3 mPosition;
    bool mMoveUp;
    bool mMoveDown;
    bool mMoveRight;
    bool mMoveLeft;
    float mRotatedX, mRotatedY, mRotatedZ;
    float mFov = 45.0f;
    glm::mat4 mViewMatrix;
    glm::mat4 mProjectionMatrix;

    void verifyMovement();
};

}
