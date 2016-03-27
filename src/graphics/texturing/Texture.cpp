//
// Created by lejonmcgowan on 3/27/16.
//

#include <algorithm>
#include "Texture.h"

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
    glGenerateMipmap(GL_TEXTURE_2D);
    unbind();
    stbi_image_free(data);
}

void Texture::unbind()
{
    glBindTexture(type, handle);
}

void Texture::bind()
{
    glBindTexture(type, 0);
}









