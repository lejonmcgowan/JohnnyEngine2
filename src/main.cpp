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

#define MODE 0

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
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    Shader vert(GL_VERTEX_SHADER,"shd/red.vert");
    Shader frag(GL_FRAGMENT_SHADER,"shd/red.frag");

#if MODE

    ShaderProgram shaderProgram;
    shaderProgram.addShader(vert);
    shaderProgram.addShader(frag);

    VertexArray vao;
    vao.addBuffer(new VertexBuffer("vertex",3),new IndexBuffer(),0);
    vao.getVBOByName("vertex")->addData(vertices);
    vao.getIBOByName("vertex")->addData(indices);
    vao.generate();



    shaderProgram.linkShaders();
    vao.generate();
#else
    SimpleRenderer2D renderer;
    Renderable2D sprite(vert,frag), sprite2(vert,frag,glm::vec4(1.0f,0.0f,0.0f,1.0f));
    sprite2.setPosition(-0.5f,-0.5f);
    sprite.init();
    sprite2.init();
#endif


    while (!window.closed())
    {
        window.clear();
        double x, y;
        window.getMousePosition(x, y);
        //std::cout << "(" << x << "," << y << ")" << std::endl;

#if MODE
        shaderProgram.setUniform("lightPos",glm::vec2(x,window.getHeight() - y));
        shaderProgram.bind();
        shaderProgram.update();
        vao.bind();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        vao.unbind();
#else
        sprite.getShaderProgram().setUniform("lightPos",glm::vec2(5.0f * x / (double)window.getWidth(),
                                                                  5.0f - 5.0f * y / (double)window.getHeight()) - 0.5f);

        sprite2.getShaderProgram().setUniform("lightPos",glm::vec2(5 * x / (double)window.getWidth(),
                                                                  5.0f - 5.0f * y / (double)window.getHeight()) - 0.5f);
        renderer.submit(sprite);
        renderer.submit(sprite2);
        renderer.flush();
#endif
        window.update();
    }

    return 0;
}