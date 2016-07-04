//
// Created by lejonmcgowan on 7/2/16.
//

#include "UniformBuffer.h"

int UniformBuffer::bindingIter = 0;
using namespace std;

UniformBuffer::UniformBuffer(std::string name) : name(name)
{
    bufferData = make_shared<UBOStruct>(name);
    bindingIndex = bindingIter++;
}

void UniformBuffer::init()
{
    glGenBuffers(1, &handle);
    glBindBuffer(GL_UNIFORM_BUFFER, handle);
    glBufferData(GL_UNIFORM_BUFFER, bufferData->calcTotalSize(), NULL, GL_STATIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, (GLuint) bindingIndex, handle);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void UniformBuffer::update()
{
    glBindBuffer(GL_UNIFORM_BUFFER, handle);
    bufferData->update(0);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}


UBOStruct &UniformBuffer::getBufferData()
{
    return *bufferData;
}


void UniformBuffer::bindToShader(Shader &shader)
{
    int uniformIndex = glGetUniformBlockIndex(shader.handle, name.c_str());
    glUniformBlockBinding(shader.handle, (GLuint) uniformIndex, (GLuint) bindingIndex);
}

void UniformBuffer::bindToShader(ShaderProgram &shader)
{
    int uniformIndex = glGetUniformBlockIndex(shader.handle, name.c_str());
    glUniformBlockBinding(shader.handle, (GLuint) uniformIndex, (GLuint) bindingIndex);
}