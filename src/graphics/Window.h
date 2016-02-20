//
// Created by lejonmcgowan on 1/7/16.
//

#ifndef OGLSIMPLEENGINE_WINDOW_H
#define OGLSIMPLEENGINE_WINDOW_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "util/Timer.h"

class Timer;
class Window
{
public:
    enum PerformanceDisplay
    {
        NONE,
        FPS,
        MILLIS,
        MICRO,
        NANO
    };
private:
    const char *title;
    int width, height;
    GLFWwindow *window;

    bool keyDowns[GLFW_KEY_LAST] = {0};
    bool mouseButtonDowns[GLFW_MOUSE_BUTTON_LAST] = {0};
    glm::dvec2 mousePosition;
    PerformanceDisplay displayType = NONE;
    Timer *windowTimer;
public:
    Window(const char *name, int width, int height);

    ~Window();

    void clear() const;

    void update();

    inline int getWidth() const
    { return width; }

    inline int getHeight() const
    { return height; }

    bool isKeyPressed(unsigned int keycode) const;

    bool isMouseButtonPressed(unsigned int button) const;

    void getMousePosition(glm::vec2 &position) const;

    void getMousePosition(double &x, double &y) const;

    bool closed() const;

private:
    bool init();

    friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

    friend void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
};

#endif //OGLSIMPLEENGINE_WINDOW_H
