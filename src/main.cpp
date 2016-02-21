#include <iostream>

#include <GL/glew.h>
#include <src/graphics/Shader.h>
#include <src/graphics/ShaderProgram.h>
#include <src/util/DebugGL.h>
#include <src/graphics/VertexArray.h>
#include <src/graphics/IndexBuffer.h>
#include <src/graphics/Renderable2D.h>
#include <src/graphics/Renderer2D.h>
#include <src/graphics/SimpleRenderer2D.h>

#include "graphics/Window.h"
#include "util/FileUtils.h"

using namespace std;

GLfloat vertices[] = {
        0.5f,  0.5f, 0.0f,  // Top Right
        0.5f, -0.5f, 0.0f,  // Bottom Right
        -0.5f, -0.5f, 0.0f,  // Bottom Left
        -0.5f,  0.5f, 0.0f   // Top Left
};

GLuint indices[] = {  // Note that we start from 0!
        0, 1, 3,  // First Triangle
        1, 2, 3   // Second Triangle
};
int main()
{
    Window window("Simple Engine!", 800,600);
    glClearColor(0.1f, 0.8f, 0.1f, 1.0f);

    Shader vert(GL_VERTEX_SHADER,"shd/red.vert");
    Shader frag(GL_FRAGMENT_SHADER,"shd/red.frag");

//    SimpleRenderer2D renderer;
//    Renderable2D sprite(vert,frag);
//
//    sprite.init();

    VertexArray vao;
    vao.addBuffer(new VertexBuffer("vertex",3),new IndexBuffer(),0);
    vao.getVBOByName("vertex")->addData(vertices);
    vao.getIBOByName("vertex")->addData(indices);
    vao.generate();

    ShaderProgram shaderProgram;
    shaderProgram.addShader(vert);
    shaderProgram.addShader(frag);

    shaderProgram.linkShaders();
    vao.generate();
    while (!window.closed())
    {
        window.clear();
        double x, y;
        window.getMousePosition(x, y);
        //std::cout << "(" << x << "," << y << ")" << std::endl;
        shaderProgram.setUniform("lightPos",glm::vec2(x,window.getHeight() - y));

#if 1
        shaderProgram.bind();
        shaderProgram.update();
        vao.bind();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        vao.unbind();
#else
        renderer.submit(sprite);
        renderer.flush();
#endif
        window.update();
    }

    return 0;
}