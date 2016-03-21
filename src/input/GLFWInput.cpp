//
// Created by lejonmcgowan on 3/21/16.
//

#include "GLFWInput.h"

GLFWInput::GLFWInput(Window &window) :
        window(window)
{

}

bool GLFWInput::isKeyPressed(unsigned int key)
{
    return glfwGetKey(window.window, key) == GLFW_PRESS;
}

bool GLFWInput::isMouseButtonPressed(unsigned int button)
{
    return glfwGetMouseButton(window.window, button) == GLFW_PRESS;
}

glm::dvec2 GLFWInput::getMousePosition()
{
    glm::dvec2 position;
    glfwGetCursorPos(window.window, &position.x, &position.y);
    return position;
}









