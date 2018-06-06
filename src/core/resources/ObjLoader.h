#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "NewLoader.h"

namespace Game
{
class ObjLoader
{
public:
    bool loadObj(const char *path,
                 std::vector<glm::vec3> &out_vertices,
                 std::vector<glm::vec2> &out_uvs,
                 std::vector<glm::vec3> &out_normals);

    bool loadObj2(const char *path,
                  std::vector<glm::vec3> &out_vertices,
                  std::vector<glm::vec2> &out_uvs,
                  std::vector<glm::vec3> &out_normals);
};
}


