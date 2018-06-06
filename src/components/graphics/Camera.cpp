#include "Camera.h"
#include "../../core/GameCore.h"


namespace Game
{
Camera::Camera()
{
    //Init with standard OGL values:
    mPosition = vec3(0.0, 0.0, 0.0);
    mViewDir = vec3(0.0, 0.0, -1.0);
    mRightVector = vec3(1.0, 0.0, 0.0);
    mUpVector = vec3(0.0, 1.0, 0.0);
    mRotatedX = mRotatedY = mRotatedZ = 0.0;
}
void Camera::configure()
{
    //    GameCore::getInstance().getEventManager().subscribe(*this);
//    GameCore::get().getEventManager().subscribe(*this);
}

void Camera::move(const vec3 &direction)
{
    mPosition += direction;
}

void Camera::rotateX(float angle)
{
    mRotatedX += angle;

    //Rotate viewdir around the right vector:
    mViewDir *= cos(angle * PIHalf);
    mUpVector *= sin(angle * PIHalf);
    mViewDir = normalize(mViewDir + mUpVector);

    //now compute the new mUpVector (by cross product)
    mUpVector = cross(mViewDir, mRightVector);
    mUpVector *= -1.0f;

}

void Camera::rotateY(GLfloat angle)
{
    mRotatedY += angle;

    //Rotate viewdir around the up vector:
    mViewDir = normalize(mViewDir * cos(angle * PIHalf) - mRightVector * sin(angle * PIHalf));
    //now compute the new RightVector (by cross product)
    mRightVector = cross(mViewDir, mUpVector);
}

void Camera::rotateZ(GLfloat angle)
{
    mRotatedZ += angle;

    //Rotate viewdir around the right vector:
    mRightVector = normalize(mRightVector * cos(angle * PIHalf) + mUpVector * sin(angle * PIHalf));

    //now compute the new mUpVector (by cross product)
    mUpVector = cross(mViewDir, mRightVector) * -1.0f;
}

void Camera::draw()
{

    //The point at which the camera looks:
    vec3 ViewPoint = mPosition + mViewDir;

    //as we know the up vector, we can easily use gluLookAt:
    mat4 mat = glm::lookAt(mPosition, ViewPoint, mUpVector);
    glMultMatrixf(&mat[0][0]);
    glTranslatef(-mPosition.x, -mPosition.y, -mPosition.z);


//        glm::mat4 ModelMatrix = glm::mat4(1.0);
//        glm::mat4 MVP = mProjectionMatrix * mViewMatrix * ModelMatrix;
//        std::cout << "1VALUE:" << MVP[0][0] << std::endl;
//        std::cout << "2VALUE:" << MVP[0][1] << std::endl;
//        std::cout << "3VALUE:" << MVP[0][2] << std::endl;
//        std::cout << "4VALUE:" << MVP[0][3] << std::endl;
//        std::cout << "5VALUE:" << MVP[1][0] << std::endl;
//        std::cout << "6VALUE:" << MVP[1][1] << std::endl;
//        std::cout << "7VALUE:" << MVP[1][2] << std::endl;
//        std::cout << "8VALUE:" << MVP[1][3] << std::endl;
//        std::cout << "9VALUE:" << MVP[2][0] << std::endl;
//        std::cout << "10VALUE:" << MVP[2][1] << std::endl;
//        std::cout << "11VALUE:" << MVP[2][2] << std::endl;
//        std::cout << "12VALUE:" << MVP[2][3] << std::endl;
//        std::cout << "13VALUE:" << MVP[3][0] << std::endl;
//        std::cout << "14VALUE:" << MVP[3][1] << std::endl;
//        std::cout << "15VALUE:" << MVP[3][2] << std::endl;
//        std::cout << "16VALUE:" << MVP[3][3] << std::endl;
//        glMultMatrixf(&mViewMatrix[0][0]);
//    /* Translate Eye to Origin */
//        glTranslatef(-mPosition.x, -mPosition.y, -mPosition.z);


}

void Camera::update()
{

    //The point at which the camera looks:
    //vec3 ViewPoint = mPosition+mViewDir;

    //as we know the up vector, we can easily use gluLookAt:
    //lookAt(mPosition, ViewPoint, mUpVector);
    verifyMovement();
}

void Camera::moveForward(GLfloat Distance)
{
    mPosition = mPosition + (mViewDir * -Distance);
}

void Camera::strafeRight(GLfloat Distance)
{
    mPosition = mPosition + (mRightVector * Distance);
}

void Camera::moveUpward(GLfloat Distance)
{
    mPosition = mPosition + (mUpVector * Distance);
}

void Camera::onKeyPress(sf::Event::KeyEvent event)
{
    switch (event.code) {
    case sf::Keyboard::Down:mMoveDown = true;
        break;
    case sf::Keyboard::Up:mMoveUp = true;
        break;
    case sf::Keyboard::Left:mMoveLeft = true;
        break;
    case sf::Keyboard::Right:mMoveRight = true;
        break;
    }
}

void Camera::onKeyDown(sf::Event::KeyEvent event)
{

}

void Camera::onKeyUp(sf::Event::KeyEvent event)
{
    switch (event.code) {
    case sf::Keyboard::Down:mMoveDown = false;
        break;
    case sf::Keyboard::Up:mMoveUp = false;
        break;
    case sf::Keyboard::Left:mMoveLeft = false;
        break;
    case sf::Keyboard::Right:mMoveRight = false;
        break;
    }
}
//
//void Camera::onMouseClick(sf::Event::MouseButtonEvent event)
//{
//
//}
//
//void Camera::onMouseMove(sf::Event::MouseMoveEvent event)
//{
//
//}

//
//mat4x4 Camera::lookAt(vec3 position, vec3 center, vec3 upVector)
//{
//    btScalar mat[16];
//
//    /* Make rotation matrix */
//
//    /* Z vector */
//    vec3 newZ = position - center;
//    newZ = normalize(newZ);
//
//    /* Y vector */
//    vec3 newY = upVector;
//
//    /* X vector = Y cross Z */
//    vec3 newX = cross(newY, newZ);
//
//    /* Recompute Y = Z cross X */
//    newY = cross(newZ, newX);
//
//    /* mpichler, 19950515 */
//    /* cross product gives area of parallelogram, which is < 1.0 for
//     * non-perpendicular unit-length vectors; so normalize x, y here
//     */
//    newX = normalize(newX);
//    newY = normalize(newY);
//
//
//    mat[0]  = newX.x,
//    mat[1]  = newX.y,
//    mat[2]  = newX.z,
//    mat[3]  = 0.0,
//    mat[4]  = newY.x,
//    mat[5]  = newY.y,
//    mat[6]  = newY.z,
//    mat[7]  = 0.0,
//    mat[8]  = newZ.x,
//    mat[9]  = newZ.y,
//    mat[10] = newZ.z,
//    mat[11] = 0.0,
//    mat[12] = 0.0,
//    mat[13] = 0.0,
//    mat[14] = 0.0,
//    mat[15] = 1.0,
//
//    glMultMatrixf(mat);
//    /* Translate Eye to Origin */
//    glTranslatef(-position.x, -position.y, -position.z);
//}



void Camera::verifyMovement()
{

    float speed = 0.01f; // 3 units / second
//
//    uint32_t deltaTime = GTime::getDelta();
//    uint32_t totalTime = GTime::getTotal();
    float horizontalAngle = 0;
    float verticalAngle = 0;

    // Compute new orientation
    //horizontalAngle += mouseSpeed * float(1024/2 - xpos );
    //verticalAngle   += mouseSpeed * float( 768/2 - ypos );

    // Direction : Spherical coordinates to Cartesian coordinates conversion
    glm::vec3 direction(
        cos(verticalAngle) * sin(horizontalAngle),
        sin(verticalAngle),
        cos(verticalAngle) * cos(horizontalAngle)
    );

    // Right vector
    glm::vec3 right = glm::vec3(
        sin(horizontalAngle - 3.14f / 2.0f),
        0,
        cos(horizontalAngle - 3.14f / 2.0f)
    );

    // Up vector
    glm::vec3 up = glm::cross(right, direction);
    float speedOverTime = 0;//deltaTime * speed;
    // Move forward
    if (mMoveUp) {
        mPosition += direction * speedOverTime;
    }
    // Move backward
    if (mMoveDown) {
        mPosition -= direction * speedOverTime;
    }
    // Strafe right
    if (mMoveRight) {
        mPosition += right * speedOverTime;
    }
    // Strafe left
    if (mMoveLeft) {
        mPosition -= right * speedOverTime;
    }

//        // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
//        mProjectionMatrix = glm::perspective(glm::radians(mFov), 4.0f / 3.0f, 0.1f, 100.0f);
//        // Camera matrix
//        mViewMatrix       = glm::lookAt(
//            mPosition,
//            mPosition+direction,
//            up
//        );

}
}
