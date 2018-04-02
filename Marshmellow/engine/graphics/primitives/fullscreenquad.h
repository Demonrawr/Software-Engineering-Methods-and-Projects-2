#ifndef FULLSCREENQUAD_H
#define FULLSCREENQUAD_H

#include "engine/graphics/primitives/shape.h"

namespace Graphics
{

    class FullScreenQuad : public Shape
    {
    public:
        FullScreenQuad();
        virtual ~FullScreenQuad();

        virtual void draw() override;
    private:
        VAO m_vao;
    };

}

#endif // FULLSCREENQUAD_H
