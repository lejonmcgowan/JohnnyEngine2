//
// Created by lejonmcgowan on 3/21/16.
//

#ifndef OGLSIMPLEENGINE_TRIANGLESCENE_H
#define OGLSIMPLEENGINE_TRIANGLESCENE_H


#include <src/graphics/buffers/VertexArray.h>
#include <src/graphics/shaderManager/Shader.h>
#include <src/graphics/shaderManager/ShaderProgram.h>
#include <src/util/Color.h>
#include "Scene.h"

class TriangleScene : public Scene
{
private:
    ShaderProgram shaderManager;
    VertexArray vao;
    Color color;
public:
    TriangleScene(GLFWInput &input);

    virtual void init() override;

    void setColor(Color color)
    { this->color = color; }

    virtual void step(float timestep) override;

    virtual void render() override;
};


#endif //OGLSIMPLEENGINE_TRIANGLESCENE_H
