#ifndef SHAPE_H
#define SHAPE_H

#include "engine/graphics/datatype/vao.h"

namespace Graphics
{

    class Shape
    {
    public:
        Shape();
        virtual ~Shape();

        virtual void draw() = 0;
    };

}

#endif // SHAPE_H
