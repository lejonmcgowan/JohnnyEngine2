//
// Created by lejonmcgowan on 1/7/16.
//

#include "src/util/DebugGL.h"
#include "Window.h"

Window::Window(const char *title, int width, int height) :
        title(title),
        width(width),
        height(height)
{
    if (!init())
        glfwTerminate();
}

Window::~Window()
{
    glfwTerminate();
}

bool Window::init()
{
    windowTimer = new Timer();

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

void Window::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update()
{
    glfwPollEvents();
    glfwSwapBuffers(window);
}

bool Window::closed() const
{
    return glfwWindowShouldClose(window) == GL_TRUE;
}

void Window::setBackgroundColor(glm::vec4 vec4)
{
    glClearColor(vec4.r, vec4.g, vec4.b, vec4.a);
}

void window_resize(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}