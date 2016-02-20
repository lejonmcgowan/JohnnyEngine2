#include <iostream>

#include <GL/glew.h>
#include <src/graphics/Shader.h>
#include <src/graphics/ShaderProgram.h>
#include <src/util/DebugGL.h>
#include <src/graphics/VertexArray.h>
#include <src/graphics/IndexBuffer.h>
#include <src/graphics/Renderable2D.h>
#include <src/graphics/Renderer2D.h>

#include "graphics/Window.h"
#include "util/FileUtils.h"

using namespace std;

GLfloat rectBuffer[12] = {0.5f,  0.5f, 0.0f,  // Top Right
                          0.5f, -0.5f, 0.0f,  // Bottom Right
                          -0.5f, -0.5f, 0.0f,  // Bottom Left
                          -0.5f,  0.5f, 0.0f   // Top Left
};

int main()
{
    Window window("Simple Engine!", 800,600);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    Shader vert(GL_VERTEX_SHADER,"shd/red.vert");
    Shader frag(GL_FRAGMENT_SHADER,"shd/red.frag");

    Renderer2D renderer;
    Renderable2D sprite(vert,frag);
    while (!window.closed())
    {
        window.clear();
        double x, y;
        window.getMousePosition(x, y);

#if 0
        glBegin(GL_QUADS);
            glVertex2f(-0.5f, -0.5f);
            glVertex2f(-0.5f,  0.5f);
            glVertex2f( 0.5f,  0.5f);
            glVertex2f( 0.5f, -0.5f);
        glEnd();
#else

#endif
        window.update();
    }

    return 0;
}