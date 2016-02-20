//
// Created by lejonmcgowan on 1/13/16.
//

#ifndef OGLSIMPLEENGINE_RENDERABLE2D_H
#define OGLSIMPLEENGINE_RENDERABLE2D_H

#include <glm/glm.hpp>
#include "VertexArray.h"
#include "ShaderProgram.h"
#include "IndexBuffer.h"

#include <memory>

class Renderable2D
{
protected:
    glm::vec3 position;
    glm::vec2 size;
    glm::vec4 color;

    std::shared_ptr<VertexArray> vao;
    //todo: possibly implement a deafult shading mechanism (after I can texture, most likely)
    std::shared_ptr<ShaderProgram> shaderProgram;
public:
    Renderable2D(Shader &, Shader &, glm::vec4 color = glm::vec4(1.0f,1.0f,1.0f,1.0f));

    void init();

    virtual ~Renderable2D();

    inline const VertexArray &getVAO() const
    { return *vao; }

    inline ShaderProgram &getShaderProgram() const
    { return *shaderProgram; }

    inline const glm::vec3 &getPosition() const
    { return position; }

    inline const glm::vec2 &getSize() const
    { return size; }

    inline const glm::vec4 &getColor() const
    { return color; }
};


#endif //OGLSIMPLEENGINE_RENDERABLE2D_H
