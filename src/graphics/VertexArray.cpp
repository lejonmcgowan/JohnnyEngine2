//
// Created by lejonmcgowan on 1/12/16.
//

#include <src/util/DebugGL.h>
#include <iostream>
#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &handle);
    checkGLError;
}

void VertexArray::addBuffer(VertexBuffer *vbo, IndexBuffer *ibo, GLuint index)
{
    IndexBuffer* finalIBO;
    if(ibo == nullptr)
        finalIBO = &IndexBuffer::nullIBO;
    else
        finalIBO = ibo;

        BufferInfo bufferInfo(*vbo,*finalIBO,index);
    buffers.emplace(vbo->getName(), bufferInfo);

    std::cout << "done" << std::endl;
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
    checkGLError;
    for (auto buffer: buffers)
    {
        GLuint index = buffer.second.index;
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, buffer.second.vbo.getComponentSize(), GL_FLOAT, GL_FALSE, 0, nullptr);

        buffer.second.vbo.bind();
        buffer.second.vbo.generate(drawType);
        if (!buffer.second.ibo.isNull())
        {
            buffer.second.ibo.bind();
            buffer.second.ibo.generate(drawType);
        }

    }

    unbind();

    checkGLError;
}

VertexBuffer* VertexArray::getVBOByName(std::string name)
{
    VertexBuffer* vbo = nullptr;
    auto mapIter = buffers.find(name);

    if(mapIter != buffers.end())
    {
        vbo = &mapIter->second.vbo;
    }

    return vbo;
}

IndexBuffer* VertexArray::getIBOByName(std::string name)
{
    IndexBuffer* ibo = nullptr;
    auto mapIter = buffers.find(name);

    if(mapIter != buffers.end())
    {
        ibo = &mapIter->second.ibo;
    }

    return ibo;
}
