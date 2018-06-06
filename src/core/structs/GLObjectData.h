#pragma once
namespace Game
{
struct GLObjectData
{
    GLObjectData()
    {
    }
    GLObjectData(GLuint vertexBuffer,
                 GLuint uvBuffer,
                 GLuint normalBuffer,
                 GLuint indexBuffer) :  vertexBuffer(vertexBuffer),
                                        uvBuffer(uvBuffer),
                                        normalBuffer(normalBuffer),
                                        indexBuffer(indexBuffer)
    {
    }
    GLuint vertexBuffer;
    GLuint uvBuffer;
    GLuint normalBuffer;
    GLuint indexBuffer;
};
}
