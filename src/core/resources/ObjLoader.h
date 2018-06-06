#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "OBJ_Loader.h"
#include "../structs/MeshTransform.h"
namespace Game
{
class ObjLoader
{
public:
    bool loadObj(const char *path, MeshTransform &outMeshTransform);
};
}


