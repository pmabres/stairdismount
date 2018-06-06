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
    static float grey;
    grey += 0.01f;
    if (grey > 1.0f) {
        grey = 0.0f;
    }

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glLoadIdentity();
//    mCamera.draw();
    glFlush();
//        mCamera.moveForward(0.001f);
//    mCamera.rotateX(0.0003f);
//        mCamera.rotateY(0.0002f);
}

//void DrawModule::resize(const glm::uint32 &width, const sf::Uint32 &height)
//{
//    glViewport(0, 0, width, height);
//}

void DrawModule::configure()
{
    glm::uint32 programId = LoadShaders();

}
void DrawModule::start()
{
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);

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

}
