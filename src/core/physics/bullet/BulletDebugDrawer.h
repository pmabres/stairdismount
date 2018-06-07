// Helper class; draws the world as seen by Bullet.
// This is very handy to see it Bullet's world matches yours
// How to use this class :
// Declare an instance of the class :
//
// dynamicsWorld->setDebugDrawer(&mydebugdrawer);
// Each frame, call it :
// mydebugdrawer.SetMatrices(ViewMatrix, ProjectionMatrix);
// dynamicsWorld->debugDrawWorld();
#include <GL/glew.h>
#include <btBulletDynamicsCommon.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../shaders/ShaderLoader.h"
namespace Game
{
//static const char* vertexShader =
//"#version 100\n"
//"attribute vec3 a_position;\n"
//"uniform mat4 MVP;\n"
//"void main()\n"
//"{\n"
//    "gl_Position = MVP*vec4(a_position, 1);\n"
//"}\n";
//
//static const char* fragmentShader =
//"#version 100\n"
//"precision mediump float;\n"
//"void main()\n"
//"{\n"
//"    gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);\n"
//"}\n";


static const char* fragmentShader =
    "#version 330 core\n"
    "in vec3 fColor;\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "    color = color;\n"
    "}\n";

static const char* vertexShader =
    "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "layout (location = 1) in vec3 color;\n"
    "out VS_OUT {\n"
    "    vec3 color;\n"
    "} vs_out;\n"
    "uniform mat4 projection;\n"
    "uniform mat4 view;\n"
    "void main()\n"
    "{\n"
    "gl_Position = projection * view * vec4(position, 1.0f);\n"
    "vs_out.color = color;\n"
    "}\n";


class BulletDebugDrawer : public btIDebugDraw {
public:
    glm::uint32_t mProgramId;
    glm::uint32_t VBO, VAO;
    void setupShaders()
    {
        mProgramId = LoadShaders(fragmentShader, vertexShader);
        glUseProgram(mProgramId);
    }

    void SetMatrices(glm::mat4 pViewMatrix, glm::mat4 pProjectionMatrix)
    {
        glUniformMatrix4fv(glGetUniformLocation(mProgramId, "projection"), 1, GL_FALSE, glm::value_ptr(pProjectionMatrix));
        glUniformMatrix4fv(glGetUniformLocation(mProgramId, "view"), 1, GL_FALSE, glm::value_ptr(pViewMatrix));
    }

    virtual void drawLine(const btVector3& from, const btVector3& to, const btVector3& color)
    {
        // Vertex data
        GLfloat points[12];

        points[0] = from.x();
        points[1] = from.y();
        points[2] = from.z();
        points[3] = color.x();
        points[4] = color.y();
        points[5] = color.z();

        points[6] = to.x();
        points[7] = to.y();
        points[8] = to.z();
        points[9] = color.x();
        points[10] = color.y();
        points[11] = color.z();

        glDeleteBuffers(1, &VBO);
        glDeleteVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(points), &points, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glBindVertexArray(0);

        glBindVertexArray(VAO);
        glDrawArrays(GL_LINES, 0, 2);
        glBindVertexArray(0);

    }
    virtual void drawContactPoint(const btVector3 &, const btVector3 &, btScalar, int, const btVector3 &) {}
    virtual void reportErrorWarning(const char *) {}
    virtual void draw3dText(const btVector3 &, const char *) {}
    virtual void setDebugMode(int p) {
        m = p;
    }
    int getDebugMode(void) const { return 3; }
    int m;
};
}





