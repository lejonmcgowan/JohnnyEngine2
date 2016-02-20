//
// Created by lejonmcgowan on 1/13/16.
//

#ifndef OGLSIMPLEENGINE_SIMPLERENDERER2D_H
#define OGLSIMPLEENGINE_SIMPLERENDERER2D_H

#include "Renderer2D.h"
#include <deque>

class SimpleRenderer2D : public Renderer2D
{
private:
    std::deque<Renderable2D> renderQueue;
public:
    void submit(const Renderable2D &renderable) override;

    void flush() override;
};

#endif //OGLSIMPLEENGINE_SIMPLERENDERER2D_H
