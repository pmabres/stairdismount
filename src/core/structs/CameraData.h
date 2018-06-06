#pragma once
#include <glm/glm.hpp>
namespace Game
{
struct CameraData
{
    CameraData()
    {
    }

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
};
}
