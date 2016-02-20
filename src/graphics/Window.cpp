//
// Created by lejonmcgowan on 1/7/16.
//

#include "src/util/DebugGL.h"
#include "Window.h"


//callback functions
void window_resize(GLFWwindow *window, int width, int height);

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Window *win = (Window *) glfwGetWindowUserPointer(window);
    win->keyDowns[key] = action != GLFW_RELEASE;
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    Window *win = (Window *) glfwGetWindowUserPointer(window);
    win->mouseButtonDowns[button] = action != GLFW_RELEASE;
}

void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{
    Window *win = (Window *) glfwGetWindowUserPointer(window);
    win->mousePosition.x = xpos;
    win->mousePosition.y = ypos;
}

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
    glfwSetWindowSizeCallback(window, window_resize);
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    assert(checkGLError);
    return true;
}

bool Window::isKeyPressed(unsigned int keycode) const
{
    // TODO: Log this!
    if (keycode >= GLFW_KEY_LAST)
        return false;

    return keyDowns[keycode];
}

bool Window::isMouseButtonPressed(unsigned int button) const
{
    // TODO: Log this!
    if (button >= GLFW_MOUSE_BUTTON_LAST)
        return false;

    return mouseButtonDowns[button];
}

void Window::getMousePosition(double &x, double &y) const
{
    x = mousePosition.x;
    y = mousePosition.y;
}

void Window::getMousePosition(glm::vec2 &position) const
{
    position.x = mousePosition.x;
    position.y = mousePosition.y;
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

void window_resize(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}