//
// Created by lejonmcgowan on 1/9/16.
//

#include <string.h>
#include "src/util/FileUtils.h"
#include "util/DebugGL.h"
#include "Shader.h"
#include "assert.h"

Shader::Shader(GLenum type, const char *filePath) : handle(glCreateShader(type)),
                                                    type(type),
                                                    filePath(filePath),
                                                    compiled(false)
{
    bool validShader = false;
    validShader |= type == GL_VERTEX_SHADER;
    validShader |= type == GL_FRAGMENT_SHADER;
    validShader |= type == GL_GEOMETRY_SHADER;
    validShader |= type == GL_TESS_CONTROL_SHADER;
    validShader |= type == GL_TESS_EVALUATION_SHADER;
    validShader |= type == GL_COMPUTE_SHADER;

    assert(validShader);
}

void Shader::compileBySource(const char *source)
{
    if (!compiled)
    {
        GLint status;
        glShaderSource(handle, 1, &source, nullptr);
        assert(checkGLError);
        glCompileShader(handle);
        assert(checkGLError);

        glGetShaderiv(handle, GL_COMPILE_STATUS, &status);
        if (status != GL_TRUE)
        {
            const int maxSize = 512;
            char errorBuf[maxSize];
            glGetShaderInfoLog(handle, maxSize, nullptr, errorBuf);
            std::cout << "WARNING: shader " << filePath << " did not compile successfully" << std::endl;
            std::cout << errorBuf << std::endl;
        }
        else
        {
            compiled = true;
        }
    }
}

void Shader::compileByPath(const char *path)
{
    if (!compiled)
    {
        assert(!filePath.empty() || strlen(path) > 0);

        std::string source;
        if (strlen(path) > 0)
            filePath = path;

        source = FileUtils::readProjectRelativeFile(filePath);

        compileBySource(source.c_str());
    }
}

Shader::~Shader()
{
    glDeleteShader(handle);
}
