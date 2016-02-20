//
// Created by lejonmcgowan on 1/9/16.
//

#include <assert.h>
#include "util/DebugGL.h"
#include "ShaderProgram.h"

void ShaderProgram::bind() const
{
    glUseProgram(handle);
    checkGLError;
}

void ShaderProgram::unbind() const
{
    glUseProgram(0);
    checkGLError;
}

ShaderProgram::ShaderProgram() : handle(glCreateProgram())
{

}

ShaderProgram::ShaderProgram(ShaderProgram &&otherProgram) :
        handle(otherProgram.handle),
        shaders(std::move(otherProgram.shaders)),
        uniforms(std::move(otherProgram.uniforms)),
        hasVertex(otherProgram.hasVertex),
        hasFrag(otherProgram.hasFrag)
{

}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(handle);
}

void ShaderProgram::addShader(GLenum type, const char *filePath = "")
{
    Shader shader(type, filePath);
    addShader(shader);
}

void ShaderProgram::addShader(Shader &shader)
{
    shader.compileByPath();
    assert(shader.compiled);

    glAttachShader(handle, shader.handle);
    assert(checkGLError);

    if (shader.type == GL_VERTEX_SHADER)
        hasVertex = true;
    if (shader.type == GL_FRAGMENT_SHADER)
        hasFrag = true;
    shaders.push_back(shader);
}

bool ShaderProgram::hasUniform(const std::string &name) const
{
    return uniforms.find(name) != uniforms.end();
}

void ShaderProgram::linkShaders()
{
    assert(hasVertex && hasFrag);

    uniforms.clear();

    glLinkProgram(handle);
    GLint status;
    glGetProgramiv(handle, GL_LINK_STATUS, &status);
    if (status != GL_TRUE)
    {
        const int maxSize = 512;
        char errorBuf[maxSize];
        glGetProgramInfoLog(handle, maxSize, nullptr, errorBuf);
        std::cout << "WARNING: shaders did not link successfully " << std::endl;
        std::cout << errorBuf << std::endl;
    }
    glValidateProgram(handle);
    assert(checkGLError);

    GLint numUniforms;
    glGetProgramiv(handle, GL_ACTIVE_UNIFORMS, &numUniforms);

    const int nameBufSize = 512;
    char nameBuf[nameBufSize];
    for (int i = 0; i < numUniforms; ++i)
    {
        GLsizei length = 0;
        GLint size = 0;
        GLenum type;
        glGetActiveUniform(handle, i, nameBufSize, &length, &size, &type, nameBuf);

        if (length < 1 || size < 1)
        {
            std::cout << "Unable to get active uniform: " << i << std::endl;
        }
        else
        {
            std::string name(nameBuf);
            GLint location = glGetUniformLocation(handle, name.c_str());
            uniforms.emplace(std::move(std::string(name)), Uniform(location, type, name));
            uniforms[name].poll(handle);
        }
    }

}

void ShaderProgram::Uniform::poll(GLuint program)
{
    switch (type)
    {
        case GL_BOOL:
            int temp;
            glGetUniformiv(program, location, &temp);
            data.boolVal = !!temp;
            break;
        case GL_INT:
        case GL_SAMPLER_1D:
        case GL_SAMPLER_2D:
        case GL_SAMPLER_3D:
        case GL_SAMPLER_CUBE:
        case GL_SAMPLER_1D_SHADOW:
        case GL_SAMPLER_2D_SHADOW:
        case GL_SAMPLER_CUBE_SHADOW:
            glGetUniformiv(program, location, &data.intVal);
            break;
        case GL_FLOAT:
            glGetUniformfv(program, location, &data.floatVal);
            break;
        case GL_FLOAT_VEC2:
            glGetUniformfv(program, location, glm::value_ptr(data.vec2Val));
            break;
        case GL_FLOAT_VEC3:
            glGetUniformfv(program, location, glm::value_ptr(data.vec3Val));
            break;
        case GL_FLOAT_VEC4:
            glGetUniformfv(program, location, glm::value_ptr(data.vec4Val));
            break;
        case GL_FLOAT_MAT2:
            glGetUniformfv(program, location, glm::value_ptr(data.mat2Val));
            break;
        case GL_FLOAT_MAT3:
            glGetUniformfv(program, location, glm::value_ptr(data.mat3Val));
            break;
        case GL_FLOAT_MAT4:
            glGetUniformfv(program, location, glm::value_ptr(data.mat4Val));
            break;
        default:
            assert(false && "Invalid uniform type");
            break;
    }

    dirty = false;
}

void ShaderProgram::Uniform::commit()
{
    switch (type)
    {
        case GL_BOOL:
            glUniform1i(location, data.boolVal);
            break;
        case GL_INT:
        case GL_SAMPLER_1D:
        case GL_SAMPLER_2D:
        case GL_SAMPLER_3D:
        case GL_SAMPLER_CUBE:
        case GL_SAMPLER_1D_SHADOW:
        case GL_SAMPLER_2D_SHADOW:
        case GL_SAMPLER_CUBE_SHADOW:
            glUniform1i(location, data.intVal);
            break;
        case GL_FLOAT:
            glUniform1f(location, data.floatVal);
            break;
        case GL_FLOAT_VEC2:
            glUniform2fv(location, 1, glm::value_ptr(data.vec2Val));
            break;
        case GL_FLOAT_VEC3:
            glUniform3fv(location, 1, glm::value_ptr(data.vec3Val));
            break;
        case GL_FLOAT_VEC4:
            glUniform4fv(location, 1, glm::value_ptr(data.vec4Val));
            break;
        case GL_FLOAT_MAT2:
            glUniformMatrix2fv(location, 1, false, glm::value_ptr(data.mat2Val));
            break;
        case GL_FLOAT_MAT3:
            glUniformMatrix3fv(location, 1, false, glm::value_ptr(data.mat3Val));
            break;
        case GL_FLOAT_MAT4:
            glUniformMatrix4fv(location, 1, false, glm::value_ptr(data.mat4Val));
            break;
        default:
            assert(false && "Invalid uniform type");
            break;
    }

    dirty = false;
}

ShaderProgram::Uniform::Uniform(const GLint location, const GLenum type, const std::string &name) :
        name(name),
        data(UniformData()),
        location(location),
        type(type)
{

}

void ShaderProgram::Uniform::setValue(bool value)
{
    assert(type == GL_BOOL);
    dirty = dirty || data.boolVal != value;
    data.boolVal = value;
}

void ShaderProgram::Uniform::setValue(int value)
{
    assert(type == GL_INT ||
           type == GL_SAMPLER_1D ||
           type == GL_SAMPLER_2D ||
           type == GL_SAMPLER_3D ||
           type == GL_SAMPLER_CUBE ||
           type == GL_SAMPLER_1D_SHADOW ||
           type == GL_SAMPLER_2D_SHADOW ||
           type == GL_SAMPLER_CUBE_SHADOW);

    dirty = dirty || data.intVal != value;
    data.intVal = value;
}

void ShaderProgram::Uniform::setValue(float value)
{
    assert(type == GL_FLOAT);
    dirty = dirty || data.floatVal != value;
    data.floatVal = value;
}

void ShaderProgram::Uniform::setValue(const glm::vec2 &value)
{
    assert(type == GL_FLOAT_VEC2);
    dirty = dirty || data.vec2Val != value;
    data.vec2Val = value;
}

void ShaderProgram::Uniform::setValue(const glm::vec3 &value)
{
    assert(type == GL_FLOAT_VEC3);
    dirty = dirty || data.vec3Val != value;
    data.vec3Val = value;
}

void ShaderProgram::Uniform::setValue(const glm::vec4 &value)
{
    assert(type == GL_FLOAT_VEC4);
    dirty = dirty || data.vec4Val != value;
    data.vec4Val = value;
}

void ShaderProgram::Uniform::setValue(const glm::mat2 &value)
{
    assert(type == GL_FLOAT_MAT2);
    dirty = dirty || data.mat2Val != value;
    data.mat2Val = value;
}

void ShaderProgram::Uniform::setValue(const glm::mat3 &value)
{
    assert(type == GL_FLOAT_MAT3);
    dirty = dirty || data.mat3Val != value;
    data.mat3Val = value;
}

void ShaderProgram::Uniform::setValue(const glm::mat4 &value)
{
    assert(type == GL_FLOAT_MAT4);
    dirty = dirty || data.mat4Val != value;
    data.mat4Val = value;
}

void ShaderProgram::update()
{
    for (auto uniformMap: uniforms)
    {
        uniformMap.second.commit();
    }
}
