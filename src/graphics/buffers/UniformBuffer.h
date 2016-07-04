//
// Created by lejonmcgowan on 7/2/16.
//

#ifndef OGLSIMPLEENGINE_UNIFORMBUFFER_H
#define OGLSIMPLEENGINE_UNIFORMBUFFER_H


#include <GL/glew.h>
#include <src/graphics/shaderManager/ShaderProgram.h>
#include "UBOStruct.h"

class UniformBuffer
{
private:
    static int bindingIter;
    int bindingIndex;
    GLuint handle;
    std::shared_ptr<UBOStruct> bufferData;
    std::string name;
public:
    UniformBuffer(std::string name);

    void init();

    void update();

    void bindToShader(Shader &shader);

    void bindToShader(ShaderProgram &shader);

    UBOStruct &getBufferData();
};


#endif //OGLSIMPLEENGINE_UNIFORMBUFFER_H
