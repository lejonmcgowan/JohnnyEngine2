//
// Created by lejonmcgowan on 1/13/16.
//

#include "SimpleRenderer2D.h"
#include <glm/gtc/matrix_transform.hpp>
#include <src/util/DebugGL.h>

void SimpleRenderer2D::submit(const Renderable2D &renderable)
{
    renderQueue.push_back(renderable);
}

void SimpleRenderer2D::flush()
{
    while (!renderQueue.empty())
    {
        glm::mat4 transform;
        Renderable2D& renderable = renderQueue.front();
        renderable.getVAO().bind();

        renderable.getShaderProgram().setUniform("model", glm::translate(transform, renderable.getPosition()));

        unsigned long size = renderable.getVAO().getIBOByName("vertex")->getBufferSize();

        glDrawElements(GL_TRIANGLES, (GLsizei) size, GL_UNSIGNED_SHORT, nullptr);
        checkGLError;
        renderable.getVAO().unbind();

        renderQueue.pop_front();
    }
}
