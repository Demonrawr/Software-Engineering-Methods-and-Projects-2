#include "sprite2d.h"

Sprite2D::Sprite2D()
{

}

Orientation2D Sprite2D::getOrientation() const
{
    return m_orientation;
}

void Sprite2D::setOrientation( const Orientation2D& orientation )
{
    m_orientation = orientation;
}



