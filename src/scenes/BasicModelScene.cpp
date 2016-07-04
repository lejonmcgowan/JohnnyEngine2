//
// Created by lejonmcgowan on 7/3/16.
//

#include <src/util/DebugGL.h>
#include "BasicModelScene.h"

void BasicModelScene::init()
{
    model = std::make_shared<Model>("assets/nanosuit2/nanosuit2.obj");
    model->init();
    modelShader.addShader(GL_VERTEX_SHADER, "shd/modelShader.vert");
    modelShader.addShader(GL_FRAGMENT_SHADER, "shd/modelShader.frag");
    modelShader.linkShaders();
    modelTransform.scaleTo(0.1f);
    modelTransform.translateBy(glm::vec3(0.0f, -0.5f, 0.0f));
}

void BasicModelScene::step(float timestep)
{

}

void BasicModelScene::render()
{
    modelShader.setUniform("projection", camera.getPerspectiveMatrix(800, 600));
    modelShader.setUniform("view", camera.getViewMatrix());
    modelShader.setUniform("model", modelTransform.getTransformMatrix());
    checkGLError;
    modelShader.update();
    checkGLError;
    model->render(modelShader);
}