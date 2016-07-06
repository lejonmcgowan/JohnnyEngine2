#include <iostream>

#include <GL/glew.h>
#include <src/util/Color.h>
#include <src/scenes/TextureTriangleScene.h>
#include <src/scenes/GLFWWindow.h>
#include <src/input/GLFWKeyboard.h>
#include <src/scenes/BasicModelScene.h>

#define MODE 0

using namespace std;

int main()
{
    GLFWWindow window("Test Window", 800, 600);
    window.setBackgroundColor(Color(0.1f, 0.1f, 0.1f, 1.0f));
    GLFWKeyboard::initialize(window.window);

    BasicModelScene scene;
    scene.init();

    while (!window.closed())
    {
        window.clear();
        scene.step(0.1f);
        scene.render();
        window.update();
    }
    return 0;
}