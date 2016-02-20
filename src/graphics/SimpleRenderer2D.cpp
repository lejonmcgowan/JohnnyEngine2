//
// Created by lejonmcgowan on 1/13/16.
//

#include "SimpleRenderer2D.h"
#include <glm/gtc/matrix_transform.hpp>

void SimpleRenderer2D::submit(const Renderable2D &renderable)
{
    renderQueue.push_back(renderable);
}

void SimpleRenderer2D::flush()
{
    while (!renderQueue.empty())
    {
        glm::mat4 transform;
        const Renderable2D& renderable = renderQueue.front();
        renderable.getVAO().bind();

        renderable.getShaderProgram().setUniform("model", glm::translate(transform, renderable.getPosition()));
        glDrawElements(GL_TRIANGLES, (GLsizei) renderable.getVAO().getIBOByName("vertex")->getBufferSize(), GL_UNSIGNED_SHORT, nullptr);

        renderable.getVAO().unbind();

        renderQueue.pop_front();
    }
}
