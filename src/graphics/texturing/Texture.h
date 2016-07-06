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
    static std::map<std::string, std::shared_ptr<Texture>> texturePool;

    GLuint handle;
    GLenum type;
    std::string path;
    unsigned int texNum;
    std::string name, uniformName;

    Texture(std::string name, GLenum type, std::string path, std::string string);
public:
    unsigned int getNextTexID();

    void init();

    inline void bind();

    inline void unbind();

    unsigned long getMaxTextures()
    { return availableTextures.size(); }

    void setTexUniform(ShaderProgram &shaderProgam, std::string uniformName = "");

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

    std::string getName() const
    {
        return name;
    }

    ~Texture();

    static std::shared_ptr<Texture> getTextureByName(std::string name);

    static std::shared_ptr<Texture> getTextureByPath(std::string path);

    static std::shared_ptr<Texture> makeTexture(std::string uniformName, GLenum type, std::string path);

    static std::shared_ptr<Texture> makeTexture(std::string uniformName, GLenum type, const char *path);

private:
    void setup();
};


#endif //OGLSIMPLEENGINE_TEXTURE_H
