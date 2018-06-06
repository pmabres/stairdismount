#pragma once
#include <glm/glm.hpp>
#include "MeshTransform.h"
#include "Transform.h"
#include "GLObjectData.h"
namespace Game
{
struct RenderStructure
{
    RenderStructure( MeshTransform& meshdata,
                     GLObjectData glData) : meshdata(meshdata), glData(glData)
    {
    }
    MeshTransform& meshdata;
    GLObjectData glData;
};
}
