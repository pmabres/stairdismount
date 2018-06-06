#pragma once

#include <list>
#include <GL/glew.h>
#include <glm/glm.hpp>
//#include "Camera.h"
#include "../interfaces/Module.h"
#include "../../resources/RenderObject.h"
#include "../../structs/ShaderData.h"
#include "../../structs/RenderStructure.h"
namespace Game
{

class DrawModule: public Module
{
public:
    DrawModule();
    ~DrawModule() = default;
    void draw() override;
    void update() override;
    void configure() override;
    void start() override;
    void stop() override;
    void cleanup() override;
    //TODO: Add remove mesh.
    glm::uint32 addMesh(MeshTransform &meshTransform);
    void drawMesh(glm::uint32 index, Transform transform);
    //void resize(const sf::Uint32 &width, const sf::Uint32 &height);
private:
    void clear();
    void useShaders();
    void shaderSetup();
    glm::vec3 mCameraPos;
    ShaderData mShaderData;
    GLuint mLightId;
    //TODO: Handle better the references so we don't copy the structure.
    std::vector<RenderStructure> mMeshVector;
    RenderObject mRenderObject;
//    Camera mCamera;
};
}
