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
    static glm::dvec2 getMousePosition()
    {
        glm::dvec2 position;
        glfwGetCursorPos(windowcontext, &position.x, &position.y);
        return position;
    }

    static void initialize(GLFWwindow *windowcontext);

    friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
};


#endif //OGLSIMPLEENGINE_INPUT_H
