//
// Created by lejonmcgowan on 1/12/16.
//

#ifndef OGLSIMPLEENGINE_VERTEXARRAY_H
#define OGLSIMPLEENGINE_VERTEXARRAY_H

#include <GL/glew.h>
#include <memory>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include <map>
#include <string>
#include <algorithm>

class VertexArray
{
private:
    struct BufferInfo
    {
        VertexBuffer *vbo;
        IndexBuffer *ibo;
        GLuint index;
    };
    GLuint handle;
    std::map<std::string, BufferInfo> buffers;
public:
    VertexArray();

    void addBuffer(VertexBuffer *vbo, IndexBuffer *ibo, GLuint index);

    VertexBuffer *getVBOByName(std::string name) const;

    IndexBuffer * getIBOByName(std::string name)const;

    void generate(GLenum drawType = GL_STATIC_DRAW);

    void bind() const;

    void unbind() const;
};

#endif //OGLSIMPLEENGINE_VERTEXARRAY_H
