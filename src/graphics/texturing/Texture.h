//
// Created by lejonmcgowan on 3/27/16.
//

#ifndef OGLSIMPLEENGINE_TEXTURE_H
#define OGLSIMPLEENGINE_TEXTURE_H


#include <GL/glew.h>
#include <vector>
#include <src/graphics/shaderManager/ShaderProgram.h>
#include <src/util/FileUtils.h>
#include "assert.h"

class Texture
{
private:
    static bool initialized;
    static std::vector<bool> availableTextures;

    GLuint handle;
    GLenum type;
    std::string path;
    unsigned int texNum;
public:

    unsigned int getNextTexID();

    Texture(GLenum type, std::string path) : type(type), path(FileUtils::getFullPath(path))
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

        texNum = getNextTexID();
        glGenTextures(1, &handle);
    }

    Texture(GLenum type, const char *path) : Texture(type, std::string(path))
    {
    }

    void init();

    inline void bind();

    inline void unbind();

    unsigned long getMaxTextures()
    { return availableTextures.size(); }

    void setTexUniform(ShaderProgram &shaderProgam, std::string uniformName);

    unsigned int getTexNum() const
    {
        return texNum;
    }

    GLuint getHandle() const
    {
        return handle;
    }

    GLenum getType() const
    {
        return type;
    }

    ~Texture();
private:
    void setup();
};


#endif //OGLSIMPLEENGINE_TEXTURE_H
