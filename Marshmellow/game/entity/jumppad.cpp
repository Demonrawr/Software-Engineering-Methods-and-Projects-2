#include "jumppad.h"

JumpPad::JumpPad( const glm::vec2& position )
{
    m_dimensions.x = 0.3f;
    m_dimensions.y  = 1.0f;
    m_orientation.position = position;
}

glm::vec2 JumpPad::getDimensions() const
{
    return m_dimensions;
}

Orientation2D JumpPad::getOrientation() const
{
    return m_orientation;
}
