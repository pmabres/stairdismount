#include "DrawEngine.h"

namespace Game
{
    void DrawEngine::draw()
    {
        static float grey;
        grey += 0.01f;
        if (grey > 1.0f)
        {
            grey = 0.0f;
        }
        //glClearColor(grey, grey, grey, 1.0f);

        glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        //glDrawArrays(GL_TRIANGLES, 0, 3);

    }

    void DrawEngine::resize(const sf::Uint32& width, const sf::Uint32& height)
    {
        glViewport(0, 0, width, height);
    }
}
