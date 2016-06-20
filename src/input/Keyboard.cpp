//
// Created by lejonmcgowan on 6/19/16.
//

#include "Keyboard.h"

unsigned char Keyboard::keyDowns[GLFW_KEY_LAST] = {0};
unsigned char Keyboard::mouseButtonDowns[GLFW_MOUSE_BUTTON_LAST] = {0};

unsigned char Keyboard::checkKeyState(unsigned int key)
{
    unsigned char keyState = keyDowns[key];
    if (keyState == GLFW_PRESS)
        keyDowns[key] = GLFW_HOLD;

    return keyState;
}

unsigned char Keyboard::checkMouseState(unsigned int button)
{
    unsigned char mouseState = mouseButtonDowns[button];
    if (mouseState == GLFW_PRESS)
        mouseButtonDowns[button] = GLFW_HOLD;

    return mouseState;
}

bool Keyboard::isKeyPressed(unsigned int key)
{

    return checkKeyState(key) == GLFW_PRESS;
}

bool Keyboard::isMouseButtonPressed(unsigned int button)
{
    return checkMouseState(button) == GLFW_PRESS;
}

bool Keyboard::isKeyHeld(unsigned int key)
{

    return checkKeyState(key) != GLFW_RELEASE;
}

bool Keyboard::isMouseButtonHeld(unsigned int button)
{
    return checkMouseState(button) != GLFW_RELEASE;
}