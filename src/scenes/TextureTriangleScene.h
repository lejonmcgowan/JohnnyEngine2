//
// Created by lejonmcgowan on 3/27/16.
//

#ifndef OGLSIMPLEENGINE_TEXTURETRIANGLESCENE_H
#define OGLSIMPLEENGINE_TEXTURETRIANGLESCENE_H


#include <src/graphics/buffers/VertexArray.h>
#include <src/graphics/shaderManager/Shader.h>
#include <src/graphics/shaderManager/ShaderProgram.h>
#include <src/util/Color.h>
#include <graphics/texturing/Texture.h>
#include <util/FileUtils.h>
#include "Scene.h"

class TextureTriangleScene : public Scene
{
private:
    ShaderProgram shaderManager;
    VertexArray vao;
    Color color;
    std::shared_ptr<Texture> checkerboardTex;
public:
    TextureTriangleScene();

    virtual void init() override;

    void setColor(Color color)
    { this->color = color; }

    virtual void step(float timestep) override;

    virtual void render() override;
};


#endif //OGLSIMPLEENGINE_TEXTURETRIANGLESCENE_H
