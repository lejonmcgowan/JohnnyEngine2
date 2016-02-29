//
// Created by lejonmcgowan on 1/13/16.
//

#include "Renderable2D.h"

/**
 * possible ideas for structuring this:
 * 1. keep a base shader inside so don't have to pass a shader in
 * 2. add shaders that you can switch to
 * */
Renderable2D::Renderable2D(Shader &vertShader, Shader &fragShader,glm::vec4 color)
        :
        position(glm::vec3(2,2,0)),
        size(glm::vec3(1,1,0)),
        color(color)
{
    shaderProgram = std::make_shared<ShaderProgram>();
    shaderProgram->addShader(vertShader);
    shaderProgram->addShader(fragShader);

    vao = std::make_shared<VertexArray>();
    GLfloat vertices[] =
            {
                    0,    0,   0,
                    0, size.y, 0,
                    size.x, size.y, 0,
                    size.x, 0, 0
            };

    GLfloat colors[] =
            {
                    color.r, color.b, color.g, color.a,
                    color.r, color.b, color.g, color.a,
                    color.r, color.b, color.g, color.a,
                    color.r, color.b, color.g, color.a
            };

    GLushort indices[] = {0, 1, 2, 2, 3, 0};

    vao->addBuffer(new VertexBuffer("vertex", 3),new IndexBuffer(), 0);
    vao->addBuffer(new VertexBuffer("color", 4),nullptr, 1);

    vao->getVBOByName("vertex")->addData(vertices);
    vao->getIBOByName("vertex")->addData(indices);

    vao->getVBOByName("color")->addData(colors);
}

Renderable2D::~Renderable2D()
{

}

void Renderable2D::init()
{
    shaderProgram->linkShaders();
    vao->generate();
}

void Renderable2D::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}


