#include <cstdio>
#include <iostream>
#include <vector>
#include "DrawModule.h"
#include "../../shaders/ShaderLoader.h"
namespace Game
{
void DrawModule::update()
{
//    mCamera.update();
}
void DrawModule::draw()
{
    clear();
    useShaders();
    // Compute the MVP matrix from keyboard and mouse input


//    computeMatricesFromInputs();
//    glm::mat4 ProjectionMatrix = getProjectionMatrix();
//    glm::mat4 ViewMatrix = getViewMatrix();
//    glm::mat4 ModelMatrix = glm::mat4(1.0);
//    glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
//
//    // Send our transformation to the currently bound shader,
//    // in the "MVP" uniform
//    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);



//    // Bind our texture in Texture Unit 0
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, Texture);
//    // Set our "myTextureSampler" sampler to user Texture Unit 0
//    glUniform1i(TextureID, 0);



    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(mModelSpaceId);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
    glVertexAttribPointer(
        mModelSpaceId,  // The attribute we want to configure
        3,                            // size
        GL_FLOAT,                     // type
        GL_FALSE,                     // normalized?
        0,                            // stride
        (void*)0                      // array buffer offset
    );

    // 2nd attribute buffer : UVs
//    glEnableVertexAttribArray(mVertexUVID);
//    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
//    glVertexAttribPointer(
//        vertexUVID,                   // The attribute we want to configure
//        2,                            // size : U+V => 2
//        GL_FLOAT,                     // type
//        GL_FALSE,                     // normalized?
//        0,                            // stride
//        (void*)0                      // array buffer offset
//    );

    // Draw the triangles !
    glDrawArrays(GL_TRIANGLES, 0, mRenderObject.out_vertices.size() );

    glDisableVertexAttribArray(mModelSpaceId);
    glDisableVertexAttribArray(mVertexUVID);


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

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glm::uint32 mProgramId = LoadShaders();

    mMatrixId = glGetUniformLocation(mProgramId, "MVP");
    mModelSpaceId = glGetAttribLocation(mProgramId, "vertexPosition_modelspace");
    mVertexUVID = glGetAttribLocation(mProgramId, "vertexUV");

    mRenderObject.load("cube.obj");
    auto vertices = mRenderObject.out_vertices;
    auto normals = mRenderObject.out_normals;
    auto uvs = mRenderObject.out_uvs;
    // Load it into a VBO

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);


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
void DrawModule::cleanup()
{
//    // Cleanup VBO and shader
//        glDeleteBuffers(1, &vertexbuffer);
//        glDeleteProgram(programID);
//        glDeleteVertexArrays(1, &VertexArrayID);
}
void DrawModule::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void DrawModule::useShaders()
{
    glUseProgram(mProgramId);
}
DrawModule::DrawModule() : mRenderObject()
{

}

}
