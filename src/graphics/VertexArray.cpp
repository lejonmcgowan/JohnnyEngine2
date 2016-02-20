//
// Created by lejonmcgowan on 1/12/16.
//

#include <src/util/DebugGL.h>
#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &handle);
    checkGLError;
}

void VertexArray::addBuffer(VertexBuffer *vbo, IndexBuffer *ibo, GLuint index)
{
    BufferInfo bufferInfo;
    bufferInfo.ibo = ibo;
    bufferInfo.vbo = vbo;
    bufferInfo.index = index;
    buffers.emplace(vbo->getName(), bufferInfo);
}

void VertexArray::bind() const
{
    glBindVertexArray(handle);
    checkGLError;
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
    checkGLError;
}

void VertexArray::generate(GLenum drawType)
{
    bind();
    for (auto buffer: buffers)
    {
        GLuint index = buffer.second.index;

        glEnableVertexAttribArray(index);
        buffer.second.vbo->generate(buffer.second.ibo, drawType);
        buffer.second.vbo->bind();

        glVertexAttribPointer(index, buffer.second.vbo->getComponentSize(), GL_FLOAT, GL_FALSE, 0, nullptr);

        checkGLError;
        buffer.second.vbo->unbind();
    }

    unbind();

    checkGLError;
}

VertexBuffer* VertexArray::getVBOByName(std::string name) const
{
    VertexBuffer* vbo;
    auto mapIter = buffers.find(name);

    if(mapIter != buffers.end())
    {
        vbo = mapIter->second.vbo;
    }

    return vbo;
}

IndexBuffer * VertexArray::getIBOByName(std::string name) const
{
    IndexBuffer* ibo;
    auto mapIter = buffers.find(name);

    if(mapIter != buffers.end())
    {
        ibo = mapIter->second.ibo;
    }

    return ibo;
}
