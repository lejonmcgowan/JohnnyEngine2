//
// Created by lejonmcgowan on 3/21/16.
//

#ifndef OGLSIMPLEENGINE_SCENE_H
#define OGLSIMPLEENGINE_SCENE_H

#include <src/input/GLFWInput.h>
#include "Window.h"

class Scene
{
protected:
    GLFWInput &input;
public:
    Scene(GLFWInput &input) : input(input)
    { }

    virtual void init() = 0;

    virtual void step(float timestep) = 0;

    virtual void render() = 0;
};

#endif //OGLSIMPLEENGINE_SCENE_H
