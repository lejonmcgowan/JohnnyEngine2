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

    vao.addBuffer(new VertexBuffer("buffer", 3), new IndexBuffer(), 0);
    vao.getVBOByName("buffer")->addData(0.5f, 0.5f, 0.0f);
    vao.getVBOByName("buffer")->addData(0.5f, -0.5f, 0.0f);
    vao.getVBOByName("buffer")->addData(-0.5f, -0.5f, 0.0f);
    vao.getVBOByName("buffer")->addData(-0.5f, 0.5f, 0.0f);

    vao.getIBOByName("buffer")->addData(0, 1, 2);
    vao.getIBOByName("buffer")->addData(0, 2, 3);

    vao.addBuffer(new VertexBuffer("color", 4), nullptr, 1);
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
    shaderManager.update();
    vao.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    vao.unbind();
}






