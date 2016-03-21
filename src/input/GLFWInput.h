//
// Created by lejonmcgowan on 3/21/16.
//

#ifndef OGLSIMPLEENGINE_INPUT_H
#define OGLSIMPLEENGINE_INPUT_H


#include <src/graphics/scenes/Window.h>
#include <GLFW/glfw3.h>

class GLFWInput
{
private:
    Window &window;
public:
    GLFWInput(Window &window);

    bool isKeyPressed(unsigned int key);

    bool isMouseButtonPressed(unsigned int button);

    glm::dvec2 getMousePosition();
};


#endif //OGLSIMPLEENGINE_INPUT_H
