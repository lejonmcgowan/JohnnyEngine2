//
// Created by lejonmcgowan on 3/21/16.
//

#include "GLFWInput.h"

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    GLFWInput *input = (GLFWInput *) glfwGetWindowUserPointer(window);
    if (action == GLFW_RELEASE)
        input->keyDowns[key] = GLFW_RELEASE;
    else if (input->keyDowns[key] == GLFW_RELEASE && action == GLFW_PRESS)
        input->keyDowns[key] = GLFW_PRESS;
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    GLFWInput *input = (GLFWInput *) glfwGetWindowUserPointer(window);
    if (action == GLFW_RELEASE)
        input->mouseButtonDowns[button] = GLFW_RELEASE;
    else if (input->mouseButtonDowns[button] == GLFW_RELEASE && action == GLFW_PRESS)
        input->mouseButtonDowns[button] = GLFW_PRESS;
}

GLFWInput::GLFWInput(Window &window) :
        window(window)
{
    glfwSetWindowUserPointer(window.window, this);
    glfwSetMouseButtonCallback(window.window, mouse_button_callback);
    glfwSetKeyCallback(window.window, key_callback);
}

glm::dvec2 GLFWInput::getMousePosition()
{
    glm::dvec2 position;
    glfwGetCursorPos(window.window, &position.x, &position.y);
    return position;
}

unsigned char GLFWInput::checkKeyState(unsigned int key)
{
    unsigned char keyState = keyDowns[key];
    if (keyState == GLFW_PRESS)
        keyDowns[key] = GLFW_HOLD;

    return keyState;
}

unsigned char GLFWInput::checkMouseState(unsigned int button)
{
    unsigned char mouseState = mouseButtonDowns[button];
    if (mouseState == GLFW_PRESS)
        mouseButtonDowns[button] = GLFW_HOLD;

    return mouseState;
}

bool GLFWInput::isKeyPressed(unsigned int key)
{

    return checkKeyState(key) == GLFW_PRESS;
}

bool GLFWInput::isMouseButtonPressed(unsigned int button)
{
    return checkMouseState(button) == GLFW_PRESS;
}

bool GLFWInput::isKeyHeld(unsigned int key)
{

    return checkKeyState(key) != GLFW_RELEASE;
}

bool GLFWInput::isMouseButtonHeld(unsigned int button)
{
    return checkMouseState(button) != GLFW_RELEASE;
}













