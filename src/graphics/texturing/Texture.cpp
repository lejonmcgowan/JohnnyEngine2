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
std::map<std::string, std::shared_ptr<Texture>> Texture::texturePool;

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
    checkGLError;
    bind();
    checkGLError;
    GLenum colorType = GL_RGB;
    if (channelPerPixel == 4)
        colorType = GL_RGBA;
    glTexImage2D(type, 0, colorType, width, height, 0, colorType, GL_UNSIGNED_BYTE, data);
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

void Texture::setTexUniform(ShaderProgram &shaderProgam, std::string uName)
{
    if (uName.empty())
        uName = uniformName;

    glActiveTexture(GL_TEXTURE0 + texNum);
    bind();
    shaderProgam.setUniform(uName, (int) handle);
}

Texture::~Texture()
{
    availableTextures[texNum] = true;
    glDeleteTextures(1, &handle);
}


Texture::Texture(std::string name, GLenum type, std::string path, std::string uniformName) : name(name),
                                                                                             type(type),
                                                                                             path(FileUtils::getFullPath(
                                                                                                     path)),
                                                                                             uniformName(uniformName)
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


std::shared_ptr<Texture> Texture::makeTexture(std::string uniformName, GLenum type, std::string path)
{
    std::string name = path.substr(path.rfind("/") + 1, path.rfind("."));
    auto texture = std::shared_ptr<Texture>(new Texture(name, type, path, uniformName));
    texturePool[name] = texture;
    availableTextures[texture->getTexNum()] = false;
    return texture;
}

std::shared_ptr<Texture> Texture::makeTexture(std::string uniformName, GLenum type, const char *path)
{
    return makeTexture(uniformName, type, std::string(path));
}

std::shared_ptr<Texture> Texture::getTextureByName(std::string name)
{
    std::shared_ptr<Texture> texture = nullptr;
    if (texturePool.find(name) != texturePool.end())
    {
        texture = texturePool[name];
    }

    return texture;
}

std::shared_ptr<Texture> Texture::getTextureByPath(std::string path)
{
    path = FileUtils::getFullPath(path);
    std::shared_ptr<Texture> finalTexture = nullptr;
    for (auto texture: texturePool)
    {
        if (texture.second->path == path)
            finalTexture = texture.second;
    }

    return finalTexture;
}
