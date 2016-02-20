//
// Created by lejonmcgowan on 1/12/16.
//

#include <src/util/DebugGL.h>
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(std::string name, GLuint chunkSize)
        : chunkSize(chunkSize),
          name(name)
{
    glGenBuffers(1, &handle);
    checkGLError;
}

inline void VertexBuffer::bind() const
{
    glBindBuffer(bufferType, handle);
    checkGLError;
}

void VertexBuffer::generate(IndexBuffer *ibo, GLenum drawType)
{
    if (!configured)
    {
        bind();
        //todo: make some option (function parameter or private variable) to change draw type
        glBufferData(bufferType, bufferData.size() * sizeof(GLfloat), &bufferData[0], drawType);
        if (ibo)
            ibo->generate(drawType);

        unbind();

        configured = true;
    }

    checkGLError;
}

void VertexBuffer::unbind() const
{
    glBindBuffer(bufferType, 0);
    checkGLError;
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &handle);
}

void VertexBuffer::addData(float data)
{
    bufferData.push_back(data);
    makeDirty();
}

void VertexBuffer::addData(float data1, float data2)
{
    bufferData.push_back(data1);
    bufferData.push_back(data2);
    makeDirty();
}

void VertexBuffer::addData(float data1, float data2, float data3)
{
    bufferData.push_back(data1);
    bufferData.push_back(data2);
    bufferData.push_back(data3);
    makeDirty();
}

void VertexBuffer::addData(float data1, float data2, float data3, float data4)
{
    bufferData.push_back(data1);
    bufferData.push_back(data2);
    bufferData.push_back(data3);
    bufferData.push_back(data4);
    makeDirty();
}

void VertexBuffer::addData(glm::vec2 data)
{
    bufferData.push_back(data.x);
    bufferData.push_back(data.y);
    makeDirty();
}

void VertexBuffer::addData(glm::vec3 data)
{
    bufferData.push_back(data.x);
    bufferData.push_back(data.y);
    bufferData.push_back(data.z);
    makeDirty();
}

void VertexBuffer::addData(glm::vec4 data)
{
    bufferData.push_back(data.x);
    bufferData.push_back(data.y);
    bufferData.push_back(data.z);
    bufferData.push_back(data.w);
    makeDirty();
}

void VertexBuffer::addData(std::vector<float> &data)
{
    for (float member: data)
        bufferData.push_back(member);
    makeDirty();
}
