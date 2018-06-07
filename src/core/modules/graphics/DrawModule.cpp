#include <cstdio>
#include <iostream>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include "DrawModule.h"
#include "../../shaders/ShaderLoader.h"
#include "../../GameCore.h"
#include "../../shaders/fragmentShader.h"
#include "../../shaders/vertexShader.h"
namespace Game
{
void DrawModule::update()
{
//    mCamera.update();
}

void DrawModule::configure()
{
    GLenum err = glewInit();
    if (err != GLEW_OK)
        std::cout << err << std::endl; // or handle the error in a nicer way
    if (!GLEW_VERSION_2_1)  // check that the machine supports the 2.1 API.
        std::cout << err << std::endl; // or handle the error in a nicer way
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    //Cornflower blue =) it reminds me of xna
    glClearColor(0.3921f, 0.5843f, 0.92941f, 0.0f);
    shaderSetup();



}
void DrawModule::start()
{


//
//        // Create and compile our GLSL program from the shaders
//        glm::uint32 programID = LoadShaders( "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader" );
//
//        // Get a handle for our "MVP" uniform
//        glm::uint32 MatrixID = glGetUniformLocation(programID, "MVP");
//
//        // Get a handle for our buffers
//        glm::uint32 vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
//        glm::uint32 vertexUVID = glGetAttribLocation(programID, "vertexUV");


//    mCamera.configure();

}
void DrawModule::stop()
{

}

void DrawModule::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void DrawModule::shaderSetup()
{

    mShaderData.programId = LoadShaders(gFragmentShader, gVertexShader);
    mShaderData.matrixId = static_cast<GLuint>(glGetUniformLocation(mShaderData.programId, "MVP"));
    mShaderData.modelSpaceId =
        static_cast<GLuint>(glGetAttribLocation(mShaderData.programId, "vertexPosition_modelspace"));
    mShaderData.vertexUVID = static_cast<GLuint>(glGetAttribLocation(mShaderData.programId, "vertexUV"));
    mShaderData.viewMatrixID = static_cast<GLuint>(glGetUniformLocation(mShaderData.programId, "V"));
    mShaderData.modelMatrixID = static_cast<GLuint>(glGetUniformLocation(mShaderData.programId, "M"));
    mShaderData.normalModelSpaceId =
        static_cast<GLuint>(glGetAttribLocation(mShaderData.programId, "vertexNormal_modelspace"));
    mLightId = static_cast<GLuint>(glGetUniformLocation(mShaderData.programId, "LightPosition_worldspace"));
}
void DrawModule::useShaders()
{
    glUseProgram(mShaderData.programId);
}
DrawModule::DrawModule() : mRenderObject()
{

}
glm::uint32 DrawModule::addMesh(MeshTransform &meshTransform)
{

    // Load it into a VBO
    GLObjectData glObjectData;
    glGenBuffers(1, &(glObjectData.vertexBuffer));
    glBindBuffer(GL_ARRAY_BUFFER, glObjectData.vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER,  meshTransform.vertices.size() * sizeof(glm::vec3), &meshTransform.vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &(glObjectData.uvBuffer));
    glBindBuffer(GL_ARRAY_BUFFER, glObjectData.uvBuffer);
    glBufferData(GL_ARRAY_BUFFER,  meshTransform.uvs.size() * sizeof(glm::vec2), &meshTransform.uvs[0], GL_STATIC_DRAW);

    glGenBuffers(1, &(glObjectData.normalBuffer));
    glBindBuffer(GL_ARRAY_BUFFER, glObjectData.normalBuffer);
    glBufferData(GL_ARRAY_BUFFER, meshTransform.normals.size() * sizeof(glm::vec3), &meshTransform.normals[0], GL_STATIC_DRAW);

    glGenBuffers(1, &(glObjectData.indexBuffer));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glObjectData.indexBuffer);
    //Was unsigned short
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshTransform.indices.size() * sizeof(glm::uint), &meshTransform.indices[0] , GL_STATIC_DRAW);

    mMeshVector.push_back(RenderStructure(meshTransform, glObjectData));
    //TODO: This needs to change
    return mMeshVector.size() - 1;
}

void DrawModule::draw()
{
    clear();
    useShaders();
//
//    glm::mat4 meshPositionMatrix = glm::mat4(1);
//    glm::mat4 MVP = mCameraData.projectionMatrix * mCameraData.viewMatrix * meshPositionMatrix;
//
//    glUniformMatrix4fv(mShaderData.matrixId, 1, GL_FALSE, &MVP[0][0]);
//    glUniformMatrix4fv(mShaderData.modelMatrixID, 1, GL_FALSE, &meshPositionMatrix[0][0]);
//    glUniformMatrix4fv(mShaderData.viewMatrixID, 1, GL_FALSE, &mCameraData.viewMatrix[0][0]);

    glm::vec3 lightPos = glm::vec3(4,4,4);
    glUniform3f(mLightId, lightPos.x, lightPos.y, lightPos.z);
}

void DrawModule::drawMesh(glm::uint32 index, Transform transform)
{

    glm::mat4 meshPositionMatrix = glm::mat4(1);
    meshPositionMatrix = glm::translate(meshPositionMatrix, transform.position);
    glm::mat4 MVP = mCameraData.projectionMatrix * mCameraData.viewMatrix * meshPositionMatrix;

    glUniformMatrix4fv(mShaderData.matrixId, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(mShaderData.modelMatrixID, 1, GL_FALSE, &meshPositionMatrix[0][0]);
    glUniformMatrix4fv(mShaderData.viewMatrixID, 1, GL_FALSE, &mCameraData.viewMatrix[0][0]);

    glEnableVertexAttribArray(mShaderData.modelSpaceId);
    glBindBuffer(GL_ARRAY_BUFFER, mMeshVector[index].glData.vertexBuffer);
    glVertexAttribPointer(
        mShaderData.modelSpaceId,  // The attribute we want to configure
        3,                            // size
        GL_FLOAT,                     // type
        GL_FALSE,                     // normalized?
        0,                            // stride
        (void*)0                      // array buffer offset
    );

    glEnableVertexAttribArray(mShaderData.vertexUVID);
    glBindBuffer(GL_ARRAY_BUFFER, mMeshVector[index].glData.uvBuffer);
    glVertexAttribPointer(
        mShaderData.vertexUVID,                   // The attribute we want to configure
        2,                            // size : U+V => 2
        GL_FLOAT,                     // type
        GL_FALSE,                     // normalized?
        0,                            // stride
        (void*)0                      // array buffer offset
    );

    glEnableVertexAttribArray(mShaderData.normalModelSpaceId);
    glBindBuffer(GL_ARRAY_BUFFER, mMeshVector[0].glData.normalBuffer);
    glVertexAttribPointer(
        mShaderData.normalModelSpaceId,    // The attribute we want to configure
        3,                            // size
        GL_FLOAT,                     // type
        GL_FALSE,                     // normalized?
        0,                            // stride
        (void*)0                      // array buffer offset
    );

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mMeshVector[0].glData.indexBuffer);

    glDrawElements(
        GL_TRIANGLES,      // mode
        mMeshVector[0].meshdata.indices.size(),    // count
        GL_UNSIGNED_INT,   // type
        (void*)0           // element array buffer offset
    );


    glDisableVertexAttribArray(mShaderData.modelSpaceId);
    glDisableVertexAttribArray(mShaderData.vertexUVID);
}
void DrawModule::cleanup()
{
// Cleanup VBO and shader
    for (auto mesh : mMeshVector)
    {
        glDeleteBuffers(1, &mesh.glData.vertexBuffer);
        glDeleteBuffers(1, &mesh.glData.uvBuffer);
        glDeleteBuffers(1, &mesh.glData.normalBuffer);
        glDeleteBuffers(1, &mesh.glData.indexBuffer);
    }

    glDeleteProgram(mShaderData.programId);
//    glDeleteTextures(1, &Texture);
}
void DrawModule::setProjection(CameraData cameraData)
{
    mCameraData = cameraData;
}
CameraData &DrawModule::getProjection()
{
    return mCameraData;
}
}
