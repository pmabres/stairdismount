#include "RenderObject.h"
namespace Game
{
bool RenderObject::load(const char *path)
{
    mObjLoader.loadObj2(path, out_vertices, out_uvs, out_normals);
}
}
