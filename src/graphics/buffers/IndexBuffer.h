//
// Created by lejonmcgowan on 2/14/16.
//

#ifndef OGLSIMPLEENGINE_INDEXBUFFER_H
#define OGLSIMPLEENGINE_INDEXBUFFER_H

#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/detail/type_vec.hpp>
#include <glm/detail/precision.hpp>


class IndexBuffer
{
private:
    GLuint handle;
    GLenum bufferType = GL_ELEMENT_ARRAY_BUFFER;
    std::vector<GLuint> bufferData;
    bool configured;

    void makeDirty()
    { configured = false; }
    IndexBuffer(bool init);
public:
    static IndexBuffer nullIBO;

    IndexBuffer();

    ~IndexBuffer();

    void generate(GLenum drawType = GL_STATIC_DRAW);

    void bind() const;

    unsigned long getBufferSize() const
    { return bufferData.size(); }

    void addData(GLuint data1);

    void addData(GLuint data1, GLuint data2);

    void addData(GLuint data1, GLuint data2, GLuint data3);

    void addData(GLuint data1, GLuint data2, GLuint data3, GLuint data4);

    void addData(glm::ivec2 data);

    void addData(glm::ivec3 data);

    void addData(glm::ivec4 data);

    template<size_t N>
    void addData(const GLuint (&data)[N])
    {
        for (GLuint member: data)
            bufferData.push_back(member);
    };

    template<size_t N>
    void addData(const GLushort (&data)[N])
    {
        for (GLushort member: data)
            bufferData.push_back(member);
    };

    void addData(std::vector<GLuint> &data);

    bool isNull()
    { return this == &nullIBO; }
};


#endif //OGLSIMPLEENGINE_INDEXBUFFER_H
