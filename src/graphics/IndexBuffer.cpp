//
// Created by lejonmcgowan on 2/14/16.
//

#include "util/DebugGL.h"
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
    glGenBuffers(1, &handle);
    checkGLError;
}

inline void IndexBuffer::bind() const
{
    glBindBuffer(bufferType, handle);
    checkGLError;
}

void IndexBuffer::generate(GLenum drawType)
{
    if (!configured)
    {
        bind();
        //todo: make some option (function parameter or private variable) to change draw type
        glBufferData(bufferType, bufferData.size() * sizeof(GLuint), &bufferData[0], drawType);
        //do NOT unbind EBO. will dissassosiate from VBO
        configured = true;
    }

    checkGLError;
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &handle);
}

void IndexBuffer::addData(GLuint data)
{
    bufferData.push_back(data);
    makeDirty();
}

void IndexBuffer::addData(GLuint data1, GLuint data2)
{
    bufferData.push_back(data1);
    bufferData.push_back(data2);
    makeDirty();
}

void IndexBuffer::addData(GLuint data1, GLuint data2, GLuint data3)
{
    bufferData.push_back(data1);
    bufferData.push_back(data2);
    bufferData.push_back(data3);
    makeDirty();
}

void IndexBuffer::addData(GLuint data1, GLuint data2, GLuint data3, GLuint data4)
{
    bufferData.push_back(data1);
    bufferData.push_back(data2);
    bufferData.push_back(data3);
    bufferData.push_back(data4);
    makeDirty();
}

void IndexBuffer::addData(glm::ivec2 data)
{
    bufferData.push_back(data.x);
    bufferData.push_back(data.y);
    makeDirty();
}

void IndexBuffer::addData(glm::ivec3 data)
{
    bufferData.push_back(data.x);
    bufferData.push_back(data.y);
    bufferData.push_back(data.z);
    makeDirty();
}

void IndexBuffer::addData(glm::ivec4 data)
{
    bufferData.push_back(data.x);
    bufferData.push_back(data.y);
    bufferData.push_back(data.z);
    bufferData.push_back(data.w);
    makeDirty();
}

void IndexBuffer::addData(std::vector<GLuint> &data)
{
    for (GLuint member: data)
        bufferData.push_back(member);
    makeDirty();
}