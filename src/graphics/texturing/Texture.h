//
// Created by lejonmcgowan on 3/27/16.
//

#ifndef OGLSIMPLEENGINE_TEXTURE_H
#define OGLSIMPLEENGINE_TEXTURE_H


#include <GL/glew.h>
#include <vector>
#include "assert.h"

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>

class Texture
{
private:
    static bool initialized = false;
    static std::vector<bool> availableTextures;
    static int texIter = 0;

    GLuint handle;
    GLenum type;
    std::string path;
    unsigned int id;
public:

    unsigned int getNextTexID();

    Texture(GLenum type, std::string path) : type(type), path(path)
    {
        if (!initialized)
            setup();

        assert(type == GL_TEXTURE_1D ||
               type == GL_TEXTURE_2D ||
               type == GL_TEXTURE_3D ||
               type == GL_TEXTURE_1D_ARRAY ||
               type == GL_TEXTURE_2D_ARRAY ||
               type == GL_TEXTURE_RECTANGLE ||
               type == GL_TEXTURE_CUBE_MAP ||
               type == GL_TEXTURE_BUFFER ||
               type == GL_TEXTURE_2D_MULTISAMPLE ||
               type == GL_TEXTURE_2D_MULTISAMPLE_ARRAY);

        id = getNextTexID();
        glGenTextures(1, &handle);
    }

    void init();

    inline void bind();

    inline void unbind();

    unsigned long getMaxTextures()
    { return availableTextures.size(); }

private:
    void setup();
};


#endif //OGLSIMPLEENGINE_TEXTURE_H
