#include <SFML/OpenGL.hpp>
#ifndef GAME_DRAWENGINE_H
#define GAME_DRAWENGINE_H

namespace Game
{
    const GLfloat gTriangleVertices[] = { 0.0f, 0.5f, -0.5f, -0.5f,
                                          0.5f, -0.5f };
    class DrawEngine
    {
    public:
        void draw();
        void resize(const sf::Uint32 &width, const sf::Uint32 &height);
    };
}


#endif //GAME_DRAWENGINE_H
