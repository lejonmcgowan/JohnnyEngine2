//
// Created by lejonmcgowan on 1/13/16.
//

#ifndef OGLSIMPLEENGINE_RENDERER2D_H
#define OGLSIMPLEENGINE_RENDERER2D_H

#include <deque>
#include "Renderable2D.h"

class Renderer2D
{
public:
    virtual void submit(const Renderable2D &renderable2D) = 0;

    virtual void flush() = 0;

};

#endif //OGLSIMPLEENGINE_RENDERER2D_H
