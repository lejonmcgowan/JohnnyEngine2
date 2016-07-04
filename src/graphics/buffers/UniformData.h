//
// Created by lejonmcgowan on 7/2/16.
//

#ifndef OGLSIMPLEENGINE_UNIFORMDATA_H
#define OGLSIMPLEENGINE_UNIFORMDATA_H


#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

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

#endif //OGLSIMPLEENGINE_UNIFORMDATA_H
