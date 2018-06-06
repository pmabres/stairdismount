#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "ObjLoader.h"
#include "../structs/MeshTransform.h"
namespace Game
{
class RenderObject
{
public:
    RenderObject() = default;
    bool load(const char *path);
    MeshTransform& getMesh();
private:
    MeshTransform mMeshTransform;
    ObjLoader mObjLoader;
};
}
