//
// Created by lejonmcgowan on 3/3/16.
//

#include <src/util/DebugGL.h>
#include "VertLineRenderer.h"

#define END_OF_PRIMITIVE_ID 99999

VertLineRenderer::VertLineRenderer()
{
    shaderProgram.addShader(GL_VERTEX_SHADER, "shd/vertexLine.vert");
    shaderProgram.addShader(GL_FRAGMENT_SHADER, "shd/vertexLine.frag");

    shaderProgram.linkShaders();
    //todo stream draw?
    vbo0 = new VertexBuffer("vbo0", 3);
    vbo1 = new VertexBuffer("vbo1", 3);
    vbo2 = new VertexBuffer("offsets", 4);

    std::vector<float> offsetDirUv;    // will contains {xy projection space offsets, uv}
    //todo does this work?
    for (int v = 0; v < LINE_RENDERER_MAX_LINES * 4 * 8; v += 4 * 8)
    {
        offsetDirUv[v] = 1.0f;
        offsetDirUv[v + 1] = 1.0f;
        offsetDirUv[v + 2] = 1.0f;
        offsetDirUv[v + 3] = 0.0f;
        offsetDirUv[v + 4] = 1.0f;
        offsetDirUv[v + 5] = -1.0f;
        offsetDirUv[v + 6] = 1.0f;
        offsetDirUv[v + 7] = 1.0f;
        offsetDirUv[v + 8] = 0.0f;
        offsetDirUv[v + 9] = 1.0f;
        offsetDirUv[v + 10] = 0.5f;
        offsetDirUv[v + 11] = 0.0f;
        offsetDirUv[v + 12] = 0.0f;
        offsetDirUv[v + 13] = -1.0f;
        offsetDirUv[v + 14] = 0.5f;
        offsetDirUv[v + 15] = 1.0f;
        offsetDirUv[v + 16] = 0.0f;
        offsetDirUv[v + 17] = -1.0f;
        offsetDirUv[v + 18] = 0.5f;
        offsetDirUv[v + 19] = 0.0f;
        offsetDirUv[v + 20] = 0.0f;
        offsetDirUv[v + 21] = 1.0f;
        offsetDirUv[v + 22] = 0.5f;
        offsetDirUv[v + 23] = 1.0f;
        offsetDirUv[v + 24] = 1.0f;
        offsetDirUv[v + 25] = -1.0f;
        offsetDirUv[v + 26] = 0.0f;
        offsetDirUv[v + 27] = 0.0f;
        offsetDirUv[v + 28] = 1.0f;
        offsetDirUv[v + 29] = 1.0f;
        offsetDirUv[v + 30] = 0.0f;
        offsetDirUv[v + 31] = 1.0f;
    }
    vbo2->addData(offsetDirUv);
    vbo2->generate(GL_STATIC_DRAW);


    //striped triangles for lines rendering with primitive restart
    ebo0 = new IndexBuffer();
    std::vector<GLuint> trisStripElements;
    GLuint lineID = 0;
    for (int t = 0; t < (LINE_RENDERER_MAX_LINES * 8 + LINE_RENDERER_MAX_LINES); t += (8 + 1), lineID += 8)
    {
        trisStripElements[t] = lineID;
        trisStripElements[t + 1] = lineID + 1;
        trisStripElements[t + 2] = lineID + 2;
        trisStripElements[t + 3] = lineID + 3;
        trisStripElements[t + 4] = lineID + 4;
        trisStripElements[t + 5] = lineID + 5;
        trisStripElements[t + 6] = lineID + 6;
        trisStripElements[t + 7] = lineID + 7;
        trisStripElements[t + 8] = END_OF_PRIMITIVE_ID; //todo wtf? change it
    }
    ebo0->addData(trisStripElements);
    ebo0->generate(GL_STATIC_DRAW);

    ebo0->bind();

    glGenVertexArrays(1, &lineVAO);
    glBindVertexArray(lineVAO);
    vbo0->bind();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *) 0);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    vbo1->bind();
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *) 0);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    vbo2->bind();
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid *) 0);
    vbo2->unbind();

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);
}


void VertLineRenderer::renderLines(const unsigned int nbLines, const float *pLines, float radius, glm::mat4 MVP,
                                   const float *mvMat, const float *pMat, GLuint texture, float screenRatio)
{
    unsigned int finalNumLines = nbLines;
    if (finalNumLines > LINE_RENDERER_MAX_LINES)
        finalNumLines = LINE_RENDERER_MAX_LINES;

    std::vector<float> vertex0, vertex1;
    //transform data into vbo arrays with vertex duplication for extrusion
    for (unsigned int l = 0; l < finalNumLines; ++l)
    {
        const int lA = l * 6;
        const int lB = l * 6 + 3;
        const int l24 = l * 24;
        vertex0[l24] = pLines[lA];
        vertex0[l24 + 1] = pLines[lA + 1];
        vertex0[l24 + 2] = pLines[lA + 2];
        vertex0[l24 + 3] = pLines[lA];
        vertex0[l24 + 4] = pLines[lA + 1];
        vertex0[l24 + 5] = pLines[lA + 2];
        vertex0[l24 + 6] = pLines[lA];
        vertex0[l24 + 7] = pLines[lA + 1];
        vertex0[l24 + 8] = pLines[lA + 2];
        vertex0[l24 + 9] = pLines[lA];
        vertex0[l24 + 10] = pLines[lA + 1];
        vertex0[l24 + 11] = pLines[lA + 2];

        vertex0[l24 + 12] = pLines[lB];
        vertex0[l24 + 13] = pLines[lB + 1];
        vertex0[l24 + 14] = pLines[lB + 2];
        vertex0[l24 + 15] = pLines[lB];
        vertex0[l24 + 16] = pLines[lB + 1];
        vertex0[l24 + 17] = pLines[lB + 2];
        vertex0[l24 + 18] = pLines[lB];
        vertex0[l24 + 19] = pLines[lB + 1];
        vertex0[l24 + 20] = pLines[lB + 2];
        vertex0[l24 + 21] = pLines[lB];
        vertex0[l24 + 22] = pLines[lB + 1];
        vertex0[l24 + 23] = pLines[lB + 2];
    }
    for (unsigned int l = 0; l < finalNumLines; ++l)
    {
        const int lA = l * 6;
        const int lB = l * 6 + 3;
        const int l24 = l * 24;
        vertex1[l24] = pLines[lB];
        vertex1[l24 + 1] = pLines[lB + 1];
        vertex1[l24 + 2] = pLines[lB + 2];
        vertex1[l24 + 3] = pLines[lB];
        vertex1[l24 + 4] = pLines[lB + 1];
        vertex1[l24 + 5] = pLines[lB + 2];
        vertex1[l24 + 6] = pLines[lB];
        vertex1[l24 + 7] = pLines[lB + 1];
        vertex1[l24 + 8] = pLines[lB + 2];
        vertex1[l24 + 9] = pLines[lB];
        vertex1[l24 + 10] = pLines[lB + 1];
        vertex1[l24 + 11] = pLines[lB + 2];

        vertex1[l24 + 12] = pLines[lA];
        vertex1[l24 + 13] = pLines[lA + 1];
        vertex1[l24 + 14] = pLines[lA + 2];
        vertex1[l24 + 15] = pLines[lA];
        vertex1[l24 + 16] = pLines[lA + 1];
        vertex1[l24 + 17] = pLines[lA + 2];
        vertex1[l24 + 18] = pLines[lA];
        vertex1[l24 + 19] = pLines[lA + 1];
        vertex1[l24 + 20] = pLines[lA + 2];
        vertex1[l24 + 21] = pLines[lA];
        vertex1[l24 + 22] = pLines[lA + 1];
        vertex1[l24 + 23] = pLines[lA + 2];
    }
    checkGLError;
    //copy data into vertex buffer object
    vbo0->setData(vertex0);
    vbo0->generate();
    checkGLError;

    vbo1->setData(vertex1);
    vbo1->generate();
    checkGLError;

    glDisable(GL_CULL_FACE);    //no neend to cull, all triangles drawn will be visible

    shaderProgram.bind();

    shaderProgram.setUniform("MVP", glm::mat4(MVP));

    shaderProgram.setUniform("radius", radius);
    shaderProgram.setUniform("invScrRatio", 1.0f / screenRatio);

    shaderProgram.setUniform("lineTexture", 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    checkGLError;

    glEnable(GL_PRIMITIVE_RESTART);
    glPrimitiveRestartIndex(END_OF_PRIMITIVE_ID);

    checkGLError;

    glBindVertexArray(lineVAO);
    ebo0->bind();
    glDrawElements(GL_TRIANGLE_STRIP, finalNumLines * (8 + 1), GL_UNSIGNED_INT, (GLvoid *) 0);
    glBindVertexArray(0);

    checkGLError;

    glDisable(GL_PRIMITIVE_RESTART);

}

VertLineRenderer::~VertLineRenderer()
{
    if (lineVAO)
        glDeleteVertexArrays(1, &lineVAO);
}







