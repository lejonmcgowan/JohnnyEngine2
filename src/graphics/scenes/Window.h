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

    void setBackgroundColor(glm::vec4 vec4);

private:
    const char *title;
    int width, height;
    GLFWwindow *window;

    PerformanceDisplay displayType = NONE;
    Timer *windowTimer;
public:
    Window(const char *name, int width, int height);

    ~Window();

    void clear() const;

    void update();

    inline int getWidth() const
    {
        return width;
    }

    inline int getHeight() const
    { return height; }


    bool closed() const;

private:
    bool init();

    friend class GLFWInput;
};

#endif //OGLSIMPLEENGINE_WINDOW_H
