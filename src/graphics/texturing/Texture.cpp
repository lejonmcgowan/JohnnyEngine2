//
// Created by lejonmcgowan on 3/27/16.
//

#include <algorithm>
#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
#include <src/util/DebugGL.h>

bool Texture::initialized = false;
std::vector<bool> Texture::availableTextures;

void Texture::setup()
{
    int maxNum;
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxNum);
    for (int i = 0; i < maxNum; i++)
        availableTextures.push_back(true);

    initialized = true;
}

unsigned int Texture::getNextTexID()
{
    auto iter = std::find(availableTextures.begin(), availableTextures.end(), true);
    assert(iter != availableTextures.end());

    *iter = false;

    return (unsigned int) (iter - availableTextures.begin());
}

void Texture::init()
{
    int width, height, channelPerPixel;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &channelPerPixel, 0);
    bind();
    glTexImage2D(type, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    checkGLError;
    glGenerateMipmap(GL_TEXTURE_2D);
    unbind();
    stbi_image_free(data);
}

void Texture::unbind()
{
    glBindTexture(type, 0);
}

void Texture::bind()
{
    glBindTexture(type, handle);
}

void Texture::setTexUniform(ShaderProgram &shaderProgam, std::string uniformName)
{
    shaderProgam.bind();
    glActiveTexture(GL_TEXTURE0 + texNum);
    bind();
    shaderProgam.setUniform(uniformName, (int) texNum);
}

Texture::~Texture()
{
    availableTextures[texNum] = true;
    glDeleteTextures(1, &handle);
}













