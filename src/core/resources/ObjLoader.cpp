#include "ObjLoader.h"

#include <stdio.h>
#include <string>

namespace Game
{
bool ObjLoader::loadObj(const char *path, MeshTransform &outMeshTransform)

{
    objl::Loader loader;
    if (loader.LoadFile(path))
    {
        glm::uint32 size = loader.LoadedMeshes[0].Vertices.size();
        // Fill vertices positions
        outMeshTransform.vertices.reserve(size);
        outMeshTransform.normals.reserve(size);
        outMeshTransform.uvs.reserve(size);

        // Go through each loaded mesh and out its contents
        for (auto vertex : loader.LoadedMeshes[0].Vertices)
        {
            auto pos = vertex.Position;
            auto uv = vertex.TextureCoordinate;
            auto nrm = vertex.Normal;
            outMeshTransform.vertices.push_back(glm::vec3(pos.X, pos.Y, pos.Z));
            outMeshTransform.normals.push_back(glm::vec3(nrm.X, nrm.Y, nrm.Z));
            outMeshTransform.uvs.push_back(glm::vec2(uv.X, uv.Y));
        }
        for (auto index : loader.LoadedMeshes[0].Indices)
        {
            outMeshTransform.indices.push_back(index);
        }
    }

}
}
