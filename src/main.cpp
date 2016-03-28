#include <iostream>

#include <GL/glew.h>
#include <src/util/Color.h>
#include <src/scenes/TextureTriangleScene.h>
#define MODE 0

using namespace std;

int main()
{
    Window window("Test Window", 800, 600);
    window.setBackgroundColor(Color(0.5f, 0.0f, 0.0f, 1.0f));
    GLFWInput input(window);

    TextureTriangleScene triangleScene(input);
    triangleScene.setColor(Color(0.0f, 0.0f, 1.0f, 1.0f));
    triangleScene.init();

    while (!window.closed())
    {
        window.clear();
        triangleScene.render();
        window.update();
    }
    return 0;
}