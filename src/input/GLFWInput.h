//
// Created by lejonmcgowan on 3/21/16.
//

#ifndef OGLSIMPLEENGINE_INPUT_H
#define OGLSIMPLEENGINE_INPUT_H


#include <src/graphics/scenes/Window.h>
#include <GLFW/glfw3.h>

#define GLFW_HOLD 2

class GLFWInput
{
private:
    Window &window;

    unsigned char keyDowns[GLFW_KEY_LAST] = {0};
    unsigned char mouseButtonDowns[GLFW_MOUSE_BUTTON_LAST] = {0};

    unsigned char checkKeyState(unsigned int key);

    unsigned char checkMouseState(unsigned int button);
public:
    GLFWInput(Window &window);

    bool isKeyPressed(unsigned int key);
    bool isMouseButtonPressed(unsigned int button);

    bool isKeyHeld(unsigned int key);

    bool isMouseButtonHeld(unsigned int button);
    glm::dvec2 getMousePosition();

    friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
};


#endif //OGLSIMPLEENGINE_INPUT_H
