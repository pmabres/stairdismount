#pragma once

#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>
#include <glm/glm.hpp>
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>

const float PI = glm::pi<float>();
const float PIHalf = glm::half_pi<float>();

using namespace glm;

class Camera
{

public:
    Camera(); //inits the values (Position: (0|0|0) Target: (0|0|-1) )
    void render (); //executes some glRotates and a glTranslate command
    //Note: You should call glLoadIdentity before using Render

    void move ( const vec3& direction );
    void rotateX ( float angle );
    void rotateY ( float angle );
    void rotateZ ( float angle );

    void moveForward ( float distance );
    void moveUpward ( float distance );
    void strafeRight ( float distance );
    void lookAt(vec3 position, vec3 viewPoint, vec3 upVector);
private:

    vec3 mViewDir;
    vec3 mRightVector;
    vec3 mUpVector;
    vec3 mPosition;

    float mRotatedX, mRotatedY, mRotatedZ;

    float fov = 45.0f;
    glm::mat4 mViewMatrix;
    glm::mat4 mProjectionMatrix;
};
