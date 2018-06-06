#pragma once
namespace Game
{
struct ShaderData
{
    ShaderData()
    {
    }

    GLuint programId;
    GLuint matrixId;
    GLuint modelSpaceId;
    GLuint vertexUVID;
    GLuint viewMatrixID;
    GLuint modelMatrixID;
    GLuint normalModelSpaceId;
};
}
