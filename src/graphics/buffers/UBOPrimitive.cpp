//
// Created by lejonmcgowan on 7/2/16.
//

#include "UBOPrimitive.h"

int UBOPrimitive::calcTotalSize()
{
    return dataSize;
}

UBOPrimitive::UBOPrimitive(std::string name, bool value) : UBOData(name)
{
    dataType = DataType::BOOL;
    dataSize = N;
    setValue(value);
}

UBOPrimitive::UBOPrimitive(std::string name, int value) : UBOData(name)
{
    dataType = DataType::INT;
    dataSize = N;
    setValue(value);
}

UBOPrimitive::UBOPrimitive(std::string name, float value) : UBOData(name)
{
    dataType = DataType::FLOAT;
    dataSize = N;
    setValue(value);
}

UBOPrimitive::UBOPrimitive(std::string name, glm::vec2 value) : UBOData(name)
{
    dataType = DataType::VEC_2;
    dataSize = 2 * N;
    setValue(value);
}

UBOPrimitive::UBOPrimitive(std::string name, glm::vec3 value) : UBOData(name)
{
    dataType = DataType::VEC_3;
    dataSize = 4 * N;
    setValue(value);
}

UBOPrimitive::UBOPrimitive(std::string name, glm::vec4 value) : UBOData(name)
{
    dataType = DataType::VEC_4;
    dataSize = 4 * N;
    setValue(value);
}

UBOPrimitive::UBOPrimitive(std::string name, glm::mat2 value) : UBOData(name)
{
    dataType = DataType::MAT_2;
    dataSize = 2 * (4 * N);
    setValue(value);
}

UBOPrimitive::UBOPrimitive(std::string name, glm::mat3 value) : UBOData(name)
{
    dataType = DataType::MAT_3;
    dataSize = 3 * (4 * N);
    setValue(value);
}

UBOPrimitive::UBOPrimitive(std::string name, glm::mat4 value) : UBOData(name)
{
    dataType = DataType::MAT_4;
    dataSize = 4 * (4 * N);
    setValue(value);
}

void UBOPrimitive::update(int currentOffset)
{
    if (dirty)
    {
        void *dataPtr;
        switch (dataType)
        {
            case DataType::BOOL:
                dataPtr = &data.boolVal;
                break;
            case DataType::INT:
                dataPtr = &data.intVal;
                break;
            case DataType::FLOAT:
                dataPtr = &data.floatVal;
                break;
            case DataType::VEC_2:
                dataPtr = &data.vec2Val;
                break;
            case DataType::VEC_3:
                dataPtr = &data.vec3Val;
                break;
            case DataType::VEC_4:
                dataPtr = &data.vec4Val;
                break;
            case DataType::MAT_2:
                dataPtr = &data.mat2Val;
                break;
            case DataType::MAT_3:
                dataPtr = &data.mat3Val;
                break;
            case DataType::MAT_4:
                dataPtr = &data.mat4Val;
                break;
        }
        glBufferSubData(GL_UNIFORM_BUFFER, currentOffset + offset, dataSize, dataPtr);
        dirty = false;
    }
}


void UBOPrimitive::setValue(bool value)
{
    assert(dataType == DataType::BOOL);
    dirty = dirty || data.boolVal != value;
    data.boolVal = value;
}

void UBOPrimitive::setValue(int value)
{
    assert(dataType == DataType::INT);
    dirty = dirty || data.intVal != value;
    data.intVal = value;
}

void UBOPrimitive::setValue(float value)
{
    assert(dataType == DataType::FLOAT);
    dirty = dirty || data.floatVal != value;
    data.floatVal = value;
}

void UBOPrimitive::setValue(const glm::vec2 &value)
{
    assert(dataType == DataType::VEC_2);
    dirty = dirty || data.vec2Val != value;
    data.vec2Val = value;
}

void UBOPrimitive::setValue(const glm::vec3 &value)
{
    assert(dataType == DataType::VEC_3);
    dirty = dirty || data.vec3Val != value;
    data.vec3Val = value;
}

void UBOPrimitive::setValue(const glm::vec4 &value)
{
    assert(dataType == DataType::VEC_4);
    dirty = dirty || data.vec4Val != value;
    data.vec4Val = value;
}

void UBOPrimitive::setValue(const glm::mat2 &value)
{
    assert(dataType == DataType::MAT_2);
    dirty = dirty || data.mat2Val != value;
    data.mat2Val = value;
}

void UBOPrimitive::setValue(const glm::mat3 &value)
{
    assert(dataType == DataType::MAT_3);
    dirty = dirty || data.mat3Val != value;
    data.mat3Val = value;
}

void UBOPrimitive::setValue(const glm::mat4 &value)
{
    assert(dataType == DataType::MAT_4);
    dirty = dirty || data.mat4Val != value;
    data.mat4Val = value;
}

std::string UBOPrimitive::getType()
{
    return "primitive";
}

UniformData UBOPrimitive::getData() const
{
    return data;
}