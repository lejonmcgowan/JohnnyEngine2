//
// Created by lejonmcgowan on 3/3/16.
//

#ifndef OGLSIMPLEENGINE_VERTLINERENDERER_H
#define OGLSIMPLEENGINE_VERTLINERENDERER_H


#include <GL/glew.h>
#include "src/graphics/shaderManager/Shader.h"
#include "src/graphics/shaderManager/ShaderProgram.h"
#include "src/graphics/buffers/VertexBuffer.h"

#define LINE_RENDERER_MAX_LINES        1024

class VertLineRenderer
{
public:
    VertLineRenderer();

    virtual ~VertLineRenderer();

    void renderLines(const unsigned int nbLines, const float *pLines, float radius, glm::mat4 MVP, const float *mvMat,
                     const float *pMat, GLuint texture, float screenRatio);

private:
    ShaderProgram shaderProgram;
    VertexBuffer *vbo0, *vbo1, *vbo2;
    IndexBuffer *ebo0;

    GLuint lineVAO;
};


#endif //OGLSIMPLEENGINE_VERTLINERENDERER_H
