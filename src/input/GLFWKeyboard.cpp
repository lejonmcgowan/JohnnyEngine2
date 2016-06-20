//
// Created by lejonmcgowan on 3/21/16.
//

#include "GLFWKeyboard.h"

GLFWwindow *GLFWKeyboard::windowcontext = nullptr;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    GLFWKeyboard *input = (GLFWKeyboard *) glfwGetWindowUserPointer(window);
    if (action == GLFW_RELEASE)
        input->keyDowns[key] = GLFW_RELEASE;
    else if (input->keyDowns[key] == GLFW_RELEASE && action == GLFW_PRESS)
        input->keyDowns[key] = GLFW_PRESS;
}


void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    GLFWKeyboard *input = (GLFWKeyboard *) glfwGetWindowUserPointer(window);
    if (action == GLFW_RELEASE)
        input->mouseButtonDowns[button] = GLFW_RELEASE;
    else if (input->mouseButtonDowns[button] == GLFW_RELEASE && action == GLFW_PRESS)
        input->mouseButtonDowns[button] = GLFW_PRESS;
}

void GLFWKeyboard::initialize(GLFWwindow *context)
{
    windowcontext = context;

    glfwSetWindowUserPointer(windowcontext, getInstance());
    glfwSetMouseButtonCallback(windowcontext, mouse_button_callback);
    glfwSetKeyCallback(windowcontext, key_callback);
}















