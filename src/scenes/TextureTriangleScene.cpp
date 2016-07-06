//
// Created by lejonmcgowan on 3/27/16.
//

#include <src/input/GLFWKeyboard.h>
#include "TextureTriangleScene.h"


TextureTriangleScene::TextureTriangleScene() : Scene()
{
    checkerboardTex = Texture::makeTexture("myTex", GL_TEXTURE_2D, "assets/checkerboard.png");
}

void TextureTriangleScene::init()
{
    shaderManager.addShader(GL_VERTEX_SHADER, "shd/textureShader.vert");
    shaderManager.addShader(GL_FRAGMENT_SHADER, "shd/textureShader.frag");
    shaderManager.linkShaders();

    vao.addBuffer(0, new VertexBuffer("buffer", 3), new IndexBuffer());
    vao.getVBOByName("buffer")->addData(0.5f, 0.5f, 0.0f);
    vao.getVBOByName("buffer")->addData(0.5f, -0.5f, 0.0f);
    vao.getVBOByName("buffer")->addData(-0.5f, -0.5f, 0.0f);
    vao.getVBOByName("buffer")->addData(-0.5f, 0.5f, 0.0f);

    vao.getIBOByName("buffer")->addData(0, 1, 2);
    vao.getIBOByName("buffer")->addData(0, 2, 3);

    vao.addBuffer(1, new VertexBuffer("color", 4));
    vao.getVBOByName("color")->addData(color);
    vao.getVBOByName("color")->addData(Color());
    vao.getVBOByName("color")->addData(color);
    vao.getVBOByName("color")->addData(Color(1.0f));

    vao.addBuffer(2, new VertexBuffer("texcoords", 2));
    vao.getVBOByName("texcoords")->addData(1.0f, 1.0f);
    vao.getVBOByName("texcoords")->addData(1.0f, 0.0f);
    vao.getVBOByName("texcoords")->addData(0.0f, 0.0f);
    vao.getVBOByName("texcoords")->addData(0.0f, 1.0f);

    vao.generate();

    checkerboardTex->init();
}

void TextureTriangleScene::step(float timestep)
{
}

void TextureTriangleScene::render()
{
    if (Keyboard::isKeyPressed(GLFW_KEY_K))
        std::cout << "k is pressed" << std::endl;
    if (Keyboard::isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
    {
        glm::vec2 position = GLFWKeyboard::getMousePosition();
        std::cout << position.x << " " << position.y << std::endl;
    }
    checkerboardTex->setTexUniform(shaderManager);
    shaderManager.update();
    vao.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    vao.unbind();
}






