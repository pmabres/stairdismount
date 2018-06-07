#pragma once
#include <glm/glm.hpp>
#include <vector>
namespace Game
{
struct MeshTransform
{
    MeshTransform()
    {
    }
    MeshTransform(std::vector<glm::vec3> verts,
                  std::vector<glm::vec2> uv,
                  std::vector<glm::vec3> nrm
    ) : vertices(verts), uvs(uv), normals(nrm)
    {
    }
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
    std::vector<glm::uint> indices;
};
}
