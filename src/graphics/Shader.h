//
// Created by lejonmcgowan on 1/9/16.
//

#ifndef OGLSIMPLEENGINE_SHADER_H
#define OGLSIMPLEENGINE_SHADER_H

#include <GL/glew.h>
#include <string>

class Shader
{
private:
    GLuint handle;
    GLenum type;
    std::string filePath;
    bool compiled;

    friend class ShaderProgram;

public:
    Shader(GLenum type, const char *filePath = "");

    ~Shader();

    void compileBySource(const char *source);

    void compileByPath(const char *path = "");

};

#endif //OGLSIMPLEENGINE_SHADER_H
