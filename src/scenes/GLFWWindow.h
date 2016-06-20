//
// Created by lejonmcgowan on 6/19/16.
//

#ifndef OGLSIMPLEENGINE_GLFWWINDOW_H
#define OGLSIMPLEENGINE_GLFWWINDOW_H


#include "Window.h"
#include <GLFW/glfw3.h>

class GLFWWindow : public Window
{
private:
    bool init() override;

public:
    GLFWwindow *window;

    GLFWWindow(const char *title, int width, int height);

    void update() override;

    bool closed() const override;

    ~GLFWWindow()
    { glfwTerminate(); }

private:
    friend class GLFWKeyboard;
};


#endif //OGLSIMPLEENGINE_GLFWWINDOW_H
