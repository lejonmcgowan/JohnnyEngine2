//
// Created by lejonmcgowan on 7/2/16.
//

#ifndef OGLSIMPLEENGINE_UBODATAARRAY_H
#define OGLSIMPLEENGINE_UBODATAARRAY_H


#include <vector>
#include "UBOData.h"
#include "UBOPrimitive.h"

class UBOPrimitiveArray : public UBOData
{
private:
    const int totalSize;
    std::vector<UBOPrimitive> data;
    UBOPrimitive::DataType dataType;
public:
    UBOPrimitiveArray(std::string name, UBOPrimitive::DataType dataType, int elemSize);

    virtual int calcTotalSize();

    virtual void update(int currentOffset);

    virtual std::string getType() override;

    void setValue(bool value, int position);

    void setValue(int value, int position);

    void setValue(float value, int position);

    void setValue(const glm::vec2 &value, int position);

    void setValue(const glm::vec3 &value, int position);

    void setValue(const glm::vec4 &value, int position);

    void setValue(const glm::mat2 &value, int position);

    void setValue(const glm::mat3 &value, int position);

    void setValue(const glm::mat4 &value, int position);

};


#endif //OGLSIMPLEENGINE_UBODATAARRAY_H
