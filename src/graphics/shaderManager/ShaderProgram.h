//
// Created by lejonmcgowan on 1/9/16.
//

#ifndef OGLSIMPLEENGINE_SHADERPROGRAM_H
#define OGLSIMPLEENGINE_SHADERPROGRAM_H

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

#include "Shader.h"

union UniformData
{
    UniformData()
    { mat4Val = glm::mat4(0); }

    UniformData(const UniformData &otherData)
    { mat4Val = otherData.mat4Val; }

    UniformData(UniformData &&otherData)
    {
        mat4Val = otherData.mat4Val;
        otherData.mat4Val = glm::mat4(0);
    }

    ~UniformData()
    { }

    bool boolVal;
    int intVal;
    float floatVal;

    glm::vec2 vec2Val;
    glm::vec3 vec3Val;
    glm::vec4 vec4Val;

    glm::mat2 mat2Val;
    glm::mat3 mat3Val;
    glm::mat4 mat4Val;
};

class ShaderProgram
{
private:
    class Uniform
    {
    private:
        UniformData data;
        const std::string name;
        const GLint location;
        const GLenum type;
        bool dirty;
    public:
        Uniform() : name(""),
                    location(-1),
                    type(0)
        { } //for the map to work. do not use.
        Uniform(const GLint location, const GLenum type, const std::string &name);

        void commit();

        void poll(GLuint program);

        GLenum getType() const
        { return type; }

        const std::string &getName() const
        { return name; }

        void setValue(bool value);

        void setValue(int value);

        void setValue(float value);

        void setValue(const glm::vec2 &value);

        void setValue(const glm::vec3 &value);

        void setValue(const glm::vec4 &value);

        void setValue(const glm::mat2 &value);

        void setValue(const glm::mat3 &value);

        void setValue(const glm::mat4 &value);
    };

    GLuint handle;
    std::vector<Shader> shaders;
    std::map<std::string, Uniform> uniforms;
    bool hasVertex, hasFrag;

public:
    ShaderProgram();

    ShaderProgram(ShaderProgram &&otherProgram);

    virtual ~ShaderProgram();

    GLuint getID() const
    { return handle; }

    void addShader(Shader &shader);

    void addShader(GLenum type, const char *filePath);

    void linkShaders();

    bool hasUniform(const std::string &name) const;

    template<typename T>
    void setUniform(const std::string &name, const T &value)
    {
        static std::vector<std::string> notFoundList;
        auto foundUniform = uniforms.find(name);
        if (foundUniform != uniforms.end())
        {
            Uniform &uniform = foundUniform->second;
            uniform.setValue(value);
        }
        else if(std::find(notFoundList.begin(),notFoundList.end(),name) == notFoundList.end())
        {
            std::cout << "Uniform with given name doesn't exist: " << name << std::endl;
            std::cout << "list of uniforms" << std::endl;
            for(auto uniform: uniforms)
            {
                std::cout << uniform.second.getName() <<  " of type" << uniform.second.getType() << std::endl;
            }
            notFoundList.push_back(name);
        }
    }

    void bind() const;

    void unbind() const;

    void update();
};

#endif //OGLSIMPLEENGINE_SHADER_H
