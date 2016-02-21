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
        position(glm::vec3()),
        size(glm::vec3(5,5,0)),
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
    VertexBuffer vertVBO("vertex", 3);
    VertexBuffer colorVBO("color", 4);

    vertVBO.addData(vertices);

    GLushort indices[] = {0, 1, 2, 2, 3, 0};
    IndexBuffer ebo;
    ebo.addData(indices);

    colorVBO.addData(colors);

    vao->addBuffer(&vertVBO, &ebo, 0);
    vao->addBuffer(&colorVBO,nullptr, 1);


}

Renderable2D::~Renderable2D()
{

}

void Renderable2D::init()
{
    vao->generate();
    shaderProgram->linkShaders();
}
