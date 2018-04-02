#ifndef SPRITE2D_H
#define SPRITE2D_H

#include "glm/glm.hpp"

#include "engine/graphics/util/util.h"
#include "engine/physics/orientation2d.h"

class Sprite2D
{
public:
    Sprite2D();

    Orientation2D getOrientation() const;
    void setOrientation( const Orientation2D& o );

private:

    Orientation2D m_orientation;
};

#endif // SPRITE2D_H
