#include "RenderObject.h"
namespace Game
{
bool RenderObject::load(const char *path)
{
    mObjLoader.loadObj(path, mMeshTransform);
}
MeshTransform &RenderObject::getMesh()
{
    return mMeshTransform;
}
}
