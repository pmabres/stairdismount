#pragma once

#include <GL/glew.h>
//#include "Camera.h"
#include "../interfaces/Module.h"
#include "../../resources/RenderObject.h"
#include <glm/glm.hpp>

namespace Game
{

class DrawModule : public Module
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
    //void resize(const sf::Uint32 &width, const sf::Uint32 &height);
private:
    void clear();
    void useShaders();
    glm::uint32 mProgramId;
    glm::uint32 mModelSpaceId;
    glm::uint32 mMatrixId;
    glm::uint32 mVertexUVID;
    glm::uint32 mVertexBuffer;
    RenderObject mRenderObject;
//    Camera mCamera;
};
}
