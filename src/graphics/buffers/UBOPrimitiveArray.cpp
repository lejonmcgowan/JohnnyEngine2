//
// Created by lejonmcgowan on 7/2/16.
//

#include "UBOPrimitiveArray.h"

UBOPrimitiveArray::UBOPrimitiveArray(std::string name, UBOPrimitive::DataType dataType, int elemSize)
        : UBOData(name),
          totalSize(elemSize)
{
    for (int i = 0; i < totalSize; i++)
    {
        std::string elemName = name;
        switch (dataType)
        {
            case UBOPrimitive::DataType::BOOL:
                data.emplace_back(elemName, false);
                break;
            case UBOPrimitive::DataType::INT:
                data.emplace_back(elemName, 0);
                break;
            case UBOPrimitive::DataType::FLOAT:
                data.emplace_back(elemName, 0.0f);
                break;
            case UBOPrimitive::DataType::VEC_2:
                data.emplace_back(elemName, glm::vec2());
                break;
            case UBOPrimitive::DataType::VEC_3:
                data.emplace_back(elemName, glm::vec3());
                break;
            case UBOPrimitive::DataType::VEC_4:
                data.emplace_back(elemName, glm::vec4());
                break;
            case UBOPrimitive::DataType::MAT_2:
                data.emplace_back(elemName, glm::mat2());
                break;
            case UBOPrimitive::DataType::MAT_3:
                data.emplace_back(elemName, glm::mat3());
                break;
            case UBOPrimitive::DataType::MAT_4:
                data.emplace_back(elemName, glm::mat4());
                break;
        }
    }
}

int UBOPrimitiveArray::calcTotalSize()
{
    return 16 * totalSize;
}

void UBOPrimitiveArray::update(int currentOffset)
{
    if (dirty)
    {
        for (int i = 0; i < data.size(); i++)
            data[i].update(offset);
    }
}

void UBOPrimitiveArray::setValue(bool value, int position)
{
    assert(dataType == UBOPrimitive::DataType::BOOL);
    data[position].setValue(value);
    dirty = dirty || data[position].isDirty();
}

void UBOPrimitiveArray::setValue(int value, int position)
{
    assert(dataType == UBOPrimitive::DataType::INT);
    data[position].setValue(value);
    dirty = dirty || data[position].isDirty();
}

void UBOPrimitiveArray::setValue(float value, int position)
{
    assert(dataType == UBOPrimitive::DataType::FLOAT);
    data[position].setValue(value);
    dirty = dirty || data[position].isDirty();
}

void UBOPrimitiveArray::setValue(const glm::vec2 &value, int position)
{
    assert(dataType == UBOPrimitive::DataType::VEC_2);
    data[position].setValue(value);
    dirty = dirty || data[position].isDirty();
}

void UBOPrimitiveArray::setValue(const glm::vec3 &value, int position)
{
    assert(dataType == UBOPrimitive::DataType::VEC_3);
    data[position].setValue(value);
    dirty = dirty || data[position].isDirty();
}

void UBOPrimitiveArray::setValue(const glm::vec4 &value, int position)
{
    assert(dataType == UBOPrimitive::DataType::VEC_4);
    data[position].setValue(value);
    dirty = dirty || data[position].isDirty();
}

void UBOPrimitiveArray::setValue(const glm::mat2 &value, int position)
{
    assert(dataType == UBOPrimitive::DataType::MAT_2);
    data[position].setValue(value);
    dirty = dirty || data[position].isDirty();
}

void UBOPrimitiveArray::setValue(const glm::mat3 &value, int position)
{
    assert(dataType == UBOPrimitive::DataType::MAT_3);
    data[position].setValue(value);
    dirty = dirty || data[position].isDirty();
}

void UBOPrimitiveArray::setValue(const glm::mat4 &value, int position)
{
    assert(dataType == UBOPrimitive::DataType::MAT_4);
    data[position].setValue(value);
    dirty = dirty || data[position].isDirty();
}

std::string UBOPrimitiveArray::getType()
{
    return "primitive array";
}