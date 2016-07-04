//
// Created by lejonmcgowan on 7/3/16.
//

#ifndef OGLSIMPLEENGINE_BASICMODELSCENE_H
#define OGLSIMPLEENGINE_BASICMODELSCENE_H


#include <graphics/shaderManager/ShaderProgram.h>
#include <graphics/models/Model.h>
#include <src/graphics/Camera.h>
#include "Scene.h"

class BasicModelScene : public Scene
{
private:
    ShaderProgram modelShader;
    std::shared_ptr<Model> model;
    Camera camera;
    Transform modelTransform;
public:
    BasicModelScene() : Scene()
    {

    }

    virtual void init();

    virtual void step(float timestep);

    virtual void render();
};


#endif //OGLSIMPLEENGINE_BASICMODELSCENE_H
