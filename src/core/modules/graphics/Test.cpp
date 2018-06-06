//#include "Test.h"
//// Include standard headers
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//#define GL_GLEXT_PROTOTYPES 1
//#define GL3_PROTOTYPES 1
//
//#include <GL3/GL3.h>
//
//// Include GLM
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//using namespace glm;
//
//#include "shaders/ShaderLoader.h"
//#include <common/texture.hpp>
//#include <common/controls.hpp>
//#include "../resources/RenderObject.h"
//
//int main( void )
//{
//
//
//
//
////    // Load the texture
////    glm::uint32 Texture = loadDDS("uvmap.DDS");
////
////    // Get a handle for our "myTextureSampler" uniform
////    glm::uint32 TextureID  = glGetUniformLocation(programID, "myTextureSampler");
//
//    // Read our .obj file
//    std::vector<glm::vec3> vertices;
//    std::vector<glm::vec2> uvs;
//    std::vector<glm::vec3> normals; // Won't be used at the moment.
//    bool res = loadOBJ("cube.obj", vertices, uvs, normals);
//
//    // Load it into a VBO
//
//    glm::uint32 vertexbuffer;
//    glGenBuffers(1, &vertexbuffer);
//    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
//
//    glm::uint32 uvbuffer;
//    glGenBuffers(1, &uvbuffer);
//    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
//    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
//
//    do{
//
//        // Clear the screen
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        // Use our shader
//        glUseProgram(programID);
//
//        // Compute the MVP matrix from keyboard and mouse input
//        computeMatricesFromInputs();
//        glm::mat4 ProjectionMatrix = getProjectionMatrix();
//        glm::mat4 ViewMatrix = getViewMatrix();
//        glm::mat4 ModelMatrix = glm::mat4(1.0);
//        glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
//
//        // Send our transformation to the currently bound shader,
//        // in the "MVP" uniform
//        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
//
//        // Bind our texture in Texture Unit 0
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, Texture);
//        // Set our "myTextureSampler" sampler to user Texture Unit 0
//        glUniform1i(TextureID, 0);
//
//        // 1rst attribute buffer : vertices
//        glEnableVertexAttribArray(vertexPosition_modelspaceID);
//        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//        glVertexAttribPointer(
//            vertexPosition_modelspaceID,  // The attribute we want to configure
//            3,                            // size
//            GL_FLOAT,                     // type
//            GL_FALSE,                     // normalized?
//            0,                            // stride
//            (void*)0                      // array buffer offset
//        );
//
//        // 2nd attribute buffer : UVs
//        glEnableVertexAttribArray(vertexUVID);
//        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
//        glVertexAttribPointer(
//            vertexUVID,                   // The attribute we want to configure
//            2,                            // size : U+V => 2
//            GL_FLOAT,                     // type
//            GL_FALSE,                     // normalized?
//            0,                            // stride
//            (void*)0                      // array buffer offset
//        );
//
//        // Draw the triangles !
//        glDrawArrays(GL_TRIANGLES, 0, vertices.size() );
//
//        glDisableVertexAttribArray(vertexPosition_modelspaceID);
//        glDisableVertexAttribArray(vertexUVID);
//
//        // Swap buffers
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//
//    } // Check if the ESC key was pressed or the window was closed
//    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
//        glfwWindowShouldClose(window) == 0 );
//
//    // Cleanup VBO and shader
//    glDeleteBuffers(1, &vertexbuffer);
//    glDeleteBuffers(1, &uvbuffer);
//    glDeleteProgram(programID);
//    glDeleteTextures(1, &TextureID);
//
//    // Close OpenGL window and terminate GLFW
//    glfwTerminate();
//
//    return 0;
//}