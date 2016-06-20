//
// Created by lejonmcgowan on 1/7/16.
//

#ifndef OGLSIMPLEENGINE_WINDOW_H
#define OGLSIMPLEENGINE_WINDOW_H

#include <iostream>
#include <GL/glew.h>
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
    PerformanceDisplay displayType = NONE;
    Timer *windowTimer;
protected:
    int width, height;
    const char *title;

    virtual bool init() = 0;
public:
    Window(const char *name, int width, int height);

    virtual ~Window();
    void clear() const;

    virtual void update() = 0;

    virtual bool closed() const = 0;


    inline int getWidth() const
    { return width; }

    inline int getHeight() const
    { return height; }
private:
    friend class Keyboard;
};

#endif //OGLSIMPLEENGINE_WINDOW_H
