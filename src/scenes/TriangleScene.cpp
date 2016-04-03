//
// Created by lejonmcgowan on 3/21/16.
//

#include <src/util/DebugGL.h>
#include "TriangleScene.h"

TriangleScene::TriangleScene(GLFWInput &input) : Scene(input)
{

}

void TriangleScene::init()
{
    shaderManager.addShader(GL_VERTEX_SHADER, "shd/colorTriangle.vert");
    shaderManager.addShader(GL_FRAGMENT_SHADER, "shd/colorTriangle.frag");
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

    vao.generate();
}

void TriangleScene::step(float timestep)
{
}

void TriangleScene::render()
{
    if (input.isKeyPressed(GLFW_KEY_K))
        std::cout << "k is pressed" << std::endl;
    if (input.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
    {
        glm::dvec2 position = input.getMousePosition();
        std::cout << position.x << " " << position.y << std::endl;
    }

    shaderManager.update();
    vao.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    vao.unbind();
}






