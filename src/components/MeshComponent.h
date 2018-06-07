#pragma once

#include "interfaces/Component.h"
#include "../core/resources/RenderObject.h"
namespace Game
{
class MeshComponent : public Component
{
public:
    MeshComponent();
    void loadMesh(const char* path);
    MeshTransform& getMeshData();
    void onCreate() override;
    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;
private:
    RenderObject mRenderObject;
    glm::uint32 mMeshId;
};

}
