#pragma once
#include <glm/glm.hpp>
namespace Game
{
struct Transform
{
    Transform() : position(), rotation()
    {
    }
    Transform(glm::vec3 pos,
                  glm::vec3 rot) : position(pos), rotation(rot)
    {
    }
    Transform(glm::vec3 pos) : position(pos), rotation()
    {
    }
    glm::vec3 position;
    glm::vec3 rotation;
};
}
