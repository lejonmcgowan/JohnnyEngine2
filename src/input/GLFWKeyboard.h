//
// Created by lejonmcgowan on 3/21/16.
//

#ifndef OGLSIMPLEENGINE_INPUT_H
#define OGLSIMPLEENGINE_INPUT_H


#include <scenes/Window.h>
#include <GLFW/glfw3.h>
#include "Keyboard.h"

class GLFWKeyboard : public Keyboard
{
private:
    static GLFWwindow *windowcontext;

    GLFWKeyboard()
    { };

    static GLFWKeyboard *getInstance()
    { return new GLFWKeyboard(); };
public:
    static glm::vec2 getMousePosition()
    {
        glm::vec2 position;
        double x, y;
        glfwGetCursorPos(windowcontext, &x, &y);
        position.x = (float) x;
        position.y = (float) y;
        return position;
    }

    static void initialize(GLFWwindow *windowcontext);

    friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
};


#endif //OGLSIMPLEENGINE_INPUT_H
