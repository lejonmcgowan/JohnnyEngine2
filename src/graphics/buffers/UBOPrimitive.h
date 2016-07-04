//
// Created by lejonmcgowan on 7/2/16.
//

#ifndef OGLSIMPLEENGINE_UBOBRIDGE_H
#define OGLSIMPLEENGINE_UBOBRIDGE_H

#include <string>
#include <map>
#include <GL/glew.h>

#include "UniformData.h"
#include "UBOData.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class UBOPrimitive : public UBOData
{
public:
    enum class DataType
    {
        BOOL,
        INT,
        FLOAT,
        VEC_2,
        VEC_3,
        VEC_4,
        MAT_2,
        MAT_3,
        MAT_4,
    };
private:
    const int N = 4; //based on GLSL docs
    DataType dataType;
    int dataSize;
    UniformData data;
public:
    virtual void update(int currentOffset) override;

    virtual std::string getType() override;


    virtual int calcTotalSize() override;

    UBOPrimitive(std::string name, bool value);

    UBOPrimitive(std::string name, int value);

    UBOPrimitive(std::string name, float value);

    UBOPrimitive(std::string name, glm::vec2 value);

    UBOPrimitive(std::string name, glm::vec3 value);

    UBOPrimitive(std::string name, glm::vec4 value);

    UBOPrimitive(std::string name, glm::mat2 value);

    UBOPrimitive(std::string name, glm::mat3 value);

    UBOPrimitive(std::string name, glm::mat4 value);

    void setValue(bool value);

    void setValue(int value);

    void setValue(float value);

    void setValue(const glm::vec2 &value);

    void setValue(const glm::vec3 &value);

    void setValue(const glm::vec4 &value);

    void setValue(const glm::mat2 &value);

    void setValue(const glm::mat3 &value);

    void setValue(const glm::mat4 &value);

    UniformData getData() const;
};


#endif //OGLSIMPLEENGINE_UBOBRIDGE_H
