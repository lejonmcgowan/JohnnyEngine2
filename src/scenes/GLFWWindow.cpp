//
// Created by lejonmcgowan on 6/19/16.
//

#include <src/util/DebugGL.h>
#include "GLFWWindow.h"


GLFWWindow::GLFWWindow(const char *title, int width, int height) :
        Window(title, width, height)
{
    if (!init())
        glfwTerminate();
}

bool GLFWWindow::init()
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW!" << std::endl;
        return false;
    }

    //make OGL context core
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to create GLFW window!" << std::endl;
        return false;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Could not initialize GLEW!" << std::endl;
        return false;
    }
    checkGLError;//gonna get invalid enum. can't do anything about it.

    glViewport(0, 0, width, height);

    glfwSetWindowUserPointer(window, this);

    std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    assert(checkGLError);
    return true;
}

void GLFWWindow::update()
{
    glfwPollEvents();
    glfwSwapBuffers(window);
}

bool GLFWWindow::closed() const
{
    return glfwWindowShouldClose(window) == GL_TRUE;
}