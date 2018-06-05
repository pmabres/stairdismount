#include "Camera.h"
#include "math.h"
#include <iostream>

#define SQR(x) (x*x)




/***************************************************************************************/

Camera::Camera()
{
    //Init with standard OGL values:
    mPosition = vec3(0.0, 0.0,0.0);
    mViewDir = vec3( 0.0, 0.0, -1.0);
    mRightVector = vec3 (1.0, 0.0, 0.0);
    mUpVector = vec3 (0.0, 1.0, 0.0);

    //Only to be sure:
    mRotatedX = mRotatedY = mRotatedZ = 0.0;
}

void Camera::move(const vec3& direction)
{
    mPosition += direction;
}

void Camera::rotateX(float angle)
{
    mRotatedX += angle;

    //Rotate viewdir around the right vector:
    mViewDir *= cos(angle*PIHalf);
    mUpVector *= sin(angle*PIHalf);
    mViewDir = normalize(mViewDir + mUpVector);

    //now compute the new mUpVector (by cross product)
    mUpVector = cross(mViewDir, mRightVector);
    mUpVector *= -1.0f;

}

void Camera::rotateY(GLfloat angle)
{
    mRotatedY += angle;

    //Rotate viewdir around the up vector:
    mViewDir = normalize(mViewDir*cos(angle*PIHalf) - mRightVector*sin(angle*PIHalf));
    //now compute the new RightVector (by cross product)
    mRightVector = cross(mViewDir, mUpVector);
}

void Camera::rotateZ(GLfloat angle)
{
    mRotatedZ += angle;

    //Rotate viewdir around the right vector:
    mRightVector = normalize(mRightVector*cos(angle*PIHalf) + mUpVector*sin(angle*PIHalf));

    //now compute the new mUpVector (by cross product)
    mUpVector = cross(mViewDir, mRightVector)*-1.0f;
}

void Camera::render( )
{

    //The point at which the camera looks:
    vec3 ViewPoint = mPosition+mViewDir;

    //as we know the up vector, we can easily use gluLookAt:
    lookAt(mPosition, ViewPoint, mUpVector);

}

void Camera::moveForward(GLfloat Distance){
    mPosition = mPosition + (mViewDir*-Distance);
}

void Camera::strafeRight(GLfloat Distance){
    mPosition = mPosition + (mRightVector*Distance);
}

void Camera::moveUpward( GLfloat Distance )
{
    mPosition = mPosition + (mUpVector*Distance);
}

void Camera::lookAt(vec3 position, vec3 center, vec3 upVector)
{
    btScalar mat[16];
    
    /* Make rotation matrix */

    /* Z vector */
    vec3 newZ = position - center;
    newZ = normalize(newZ);

    /* Y vector */
    vec3 newY = upVector;

    /* X vector = Y cross Z */
    vec3 newX = cross(newY, newZ);

    /* Recompute Y = Z cross X */
    newY = cross(newZ, newX);

    /* mpichler, 19950515 */
    /* cross product gives area of parallelogram, which is < 1.0 for
     * non-perpendicular unit-length vectors; so normalize x, y here
     */
    newX = normalize(newX);
    newY = normalize(newY);


    mat[0]  = newX.x,
    mat[1]  = newX.y,
    mat[2]  = newX.z,
    mat[3]  = 0.0,
    mat[4]  = newY.x,
    mat[5]  = newY.y,
    mat[6]  = newY.z,
    mat[7]  = 0.0,
    mat[8]  = newZ.x,
    mat[9]  = newZ.y,
    mat[10] = newZ.z,
    mat[11] = 0.0,
    mat[12] = 0.0,
    mat[13] = 0.0,
    mat[14] = 0.0,
    mat[15] = 1.0,

    glMultMatrixf(mat);
    /* Translate Eye to Origin */
    glTranslatef(-position.x, -position.y, -position.z);
}


//
//void computeMatricesFromInputs(){
//
//    float speed = 3.0f; // 3 units / second
//    float mouseSpeed = 0.005f;
//
//    // glfwGetTime is called only once, the first time this function is called
//    static double lastTime = glfwGetTime();
//
//    // Compute time difference between current and last frame
//    double currentTime = glfwGetTime();
//    float deltaTime = float(currentTime - lastTime);
//
//    // Get mouse position
//    double xpos, ypos;
//    glfwGetCursorPos(window, &xpos, &ypos);
//
//    // Reset mouse position for next frame
//    glfwSetCursorPos(window, 1024/2, 768/2);
//
//    // Compute new orientation
//    horizontalAngle += mouseSpeed * float(1024/2 - xpos );
//    verticalAngle   += mouseSpeed * float( 768/2 - ypos );
//
//    // Direction : Spherical coordinates to Cartesian coordinates conversion
//    glm::vec3 direction(
//            cos(verticalAngle) * sin(horizontalAngle),
//            sin(verticalAngle),
//            cos(verticalAngle) * cos(horizontalAngle)
//    );
//
//    // Right vector
//    glm::vec3 right = glm::vec3(
//            sin(horizontalAngle - 3.14f/2.0f),
//            0,
//            cos(horizontalAngle - 3.14f/2.0f)
//    );
//
//    // Up vector
//    glm::vec3 up = glm::cross( right, direction );
//
//    // Move forward
//    if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
//        position += direction * deltaTime * speed;
//    }
//    // Move backward
//    if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
//        position -= direction * deltaTime * speed;
//    }
//    // Strafe right
//    if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
//        position += right * deltaTime * speed;
//    }
//    // Strafe left
//    if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
//        position -= right * deltaTime * speed;
//    }
//
//    float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.
//
//    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
//    ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
//    // Camera matrix
//    ViewMatrix       = glm::lookAt(
//            position,           // Camera is here
//            position+direction, // and looks here : at the same position, plus "direction"
//            up                  // Head is up (set to 0,-1,0 to look upside-down)
//    );
//
//    // For the next frame, the "last time" will be "now"
//    lastTime = currentTime;
//}