//
// Created by lejonmcgowan on 1/7/16.
//

#include "src/util/DebugGL.h"
#include "Window.h"
#include "GLFWWindow.h"

Window::Window(const char *title, int width, int height) :
        title(title),
        width(width),
        height(height)
{
    windowTimer = new Timer();
}

Window::~Window()
{

}

void Window::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::setBackgroundColor(glm::vec4 vec4)
{
    glClearColor(vec4.r, vec4.g, vec4.b, vec4.a);
}

void window_resize(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}