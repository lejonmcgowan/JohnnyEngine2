//
// Created by lejonmcgowan on 6/19/16.
//

#ifndef OGLSIMPLEENGINE_KEYBOARD_H
#define OGLSIMPLEENGINE_KEYBOARD_H


#include <scenes/Window.h>
#include <GLFW/glfw3.h>

#define GLFW_HOLD 2

//todo should properly make a genreic key and key state interface. lazy atm
class Keyboard
{
private:
    static unsigned char checkKeyState(unsigned int key);

    static unsigned char checkMouseState(unsigned int button);

protected:
    static unsigned char keyDowns[GLFW_KEY_LAST];
    static unsigned char mouseButtonDowns[GLFW_MOUSE_BUTTON_LAST];
public:
    static bool isKeyPressed(unsigned int key);

    static bool isMouseButtonPressed(unsigned int button);

    static bool isKeyHeld(unsigned int key);

    static bool isMouseButtonHeld(unsigned int button);
};


#endif //OGLSIMPLEENGINE_KEYBOARD_H
