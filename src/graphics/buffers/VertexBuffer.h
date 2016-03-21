//
// Created by lejonmcgowan on 1/12/16.
//

#ifndef OGLSIMPLEENGINE_BUFFER_H
#define OGLSIMPLEENGINE_BUFFER_H

#include <GL/glew.h>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glm/detail/type_vec.hpp>
#include <glm/detail/precision.hpp>
#include "IndexBuffer.h"

class VertexBuffer
{
private:
    GLuint handle;
    GLenum bufferType = GL_ARRAY_BUFFER;
    std::vector<GLfloat> bufferData;
    GLuint chunkSize; //for the VAO
    bool configured;
    std::string name;

    inline void makeDirty()
    { configured = false; }

public:
    VertexBuffer(std::string name, GLuint chunkSize);

    ~VertexBuffer();

    void generate(GLenum drawType = GL_STATIC_DRAW);

    void bind() const;

    void unbind() const;

    GLuint getComponentSize() const
    { return chunkSize; }

    unsigned long getBufferSize() const
    { return bufferData.size(); }

    std::string getName()
    { return name; }

    void addData(float data1);

    void addData(float data1, float data2);

    void addData(float data1, float data2, float data3);

    void addData(float data1, float data2, float data3, float data4);

    void addData(glm::vec2 data);

    void addData(glm::vec3 data);

    void addData(glm::vec4 data);

    template<size_t N>
    void addData(const float (&data)[N])
    {
        for (float member: data)
            bufferData.push_back(member);

        makeDirty();

    };

    template<size_t N>
    void addData(GLfloat (&data)[N])
    {
        for (float member: data)
            bufferData.push_back(member);

        makeDirty();

    };

    void addData(std::vector<GLfloat> &data);

    void setData(std::vector<float> vector);
};

#endif //OGLSIMPLEENGINE_BUFFER_H
